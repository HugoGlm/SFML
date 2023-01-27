Param(
    [parameter()]
    [String]$path
)

function IsPublic
{
   param([string]$line, [boolean]$result)
   
   if ($line.Contains("public:"))
   {
       return $true
   }
   elseif ($line.Contains("private:") -or $line.Contains("protected:")) 
   {
       return $false
   }
   return $result
}

function AddFlag
{
    param([string]$currentFlag, [string]$newFlag)
    if ($currentFlag.Contains($newFlag))
    {
        return $currentFlag
    }
    if  ([string]::IsNullOrEmpty($currentFlag))
    {
        return "BindingFlags::$newFlag"
    }
    return "$currentFlag | BindingFlags::$newFlag"
}

function ReplaceStr
{
    param([string]$str, [string[]]$toReplace, [string]$to)
    for ($i = 0; $i -lt $toReplace.Count; $i = $i +1)
    {
        $str = $str.Replace($toReplace[$i], $to)
    }
    return $str
}

$scriptPath = $path + "/Test/ATest.h"
$className = (Get-Item $scriptPath).BaseName
$filecontents = Get-Content -Path $scriptPath
$isPublic = $false
$isStatic = $false
$flags = ""
$indexFile = 0

for ($i = 0; $i -lt $filecontents.Count; $i = $i + 1)
{
    $line = $filecontents[$i]
    $isPublic = IsPublic -line $line -result $isPublic
    if ($line -match "UFUNCTION\(\)")
    {
        $function = ReplaceStr -str $line -toReplace @("UFUNCTION()", "static", "const", "inline") -to ""
        $function = $function.TrimStart()

        $startIndex = $function.IndexOf(' ') + 1
        $functionName = $function.Substring($startIndex, $function.IndexOf('(') - $startIndex)
        $startIndex = $function.IndexOf('(') + 1
        $parameters = $function.Substring($startIndex, $function.IndexOf(')') - $startIndex)
        
        $result = "REGISTER_METHOD($functionName, &$className::$functionName,"
        if ([string]::IsNullOrEmpty($parameters.Trim()))
        {
            $result += "{},"
        }
        else
        {
            $result += "(std::vector<Engine::Reflection::ParameterInfo*>{"
            # assign parameters
            $spliterParameters = $parameters.Split(',')
            for ($j = 0; $j -lt $spliterParameters.Count; $j = $j + 1)
            {
                $param = $spliterParameters[$j].TrimStart()
                $parametersName = ReplaceStr -str $parametersName -toReplace @("const", "*", "&") -to ""
                $parametersName = $param.Substring($param.LastIndexOf(' ') + 1).Trim()
                $result += "new Engine::Reflection::ParameterInfo(`"$parametersName`", $j)"
                if ($j -lt $spliterParameters.Count - 1)
                {
                    $result += ","
                }
            }
            $result += "}), "
        }
        if ($isPublic)
        {
            $flags = AddFlag -currentFlag $flags -newFlag "Public"
        }
        else
        {
            $flags = AddFlag -currentFlag $flags -newFlag "NoPublic"

        }
        if ($isStatic)
        {
            $flags = AddFlag -currentFlag $flags -newFlag "Static"
        }
        $result += "$flags);"

        $file = (Get-Content $scriptPath) -as [Collections.ArrayList]
        if ($filecontents[$i + 1] -match "REGISTER_METHOD")
        {
            $file.RemoveAt($i + 1)
            $file.Insert($i + 1, $result)
        }
        else
        {
            $file.Insert($i + $indexFile + 1, $result)
            $indexFile = $indexFile + 1
        }
        $file | Set-Content $scriptPath
    }
}

for ($i = 0; $i -lt $filecontents.Count; $i = $i + 1)
{
    $line = $filecontents[$i]
    if ($line -match "REGISTER_METHOD" -and $filecontents[$i - 1] -notmatch "UFUNCTION")
    {
        $file = (Get-Content $scrpitpath) -as [Collections.ArrayList]
        $file.remove($i)
        $file | Set-Content $scriptPath
    }
}