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

Get-ChildItem $path -Recurse -Filter *.h | Foreach-Object
{
    $fullpath = $_.FullName
    $className = (Get-Item $fullpath).BaseName
    $includePath = $fullPath.Replace($path, "")
    $includePath = $includePath.Substring(0, $includePath.Length)
    $includePath = $includePath.Replace("\", "/")

    $fileContent = Get-Content -Path $includePath
    $isPublic = $false
    $isObject = $false
    $flags = ""

    for ($i = 0; $i -lt $fileContent.Count; $i = $i + 1) 
    {
        $line = $fileContent[$i]
        if ($line -match "UPROPERTY\(\)" -and $line -notmatch "#define UPROPERTY\(...\)")
        {
            $isObject = $true
        }
    
        if ( [string]::IsNullOrEmpty($line))
        {
            continue
        }
    
        $isPublic = IsPublic -line $line -result $isPublic
    
        if ($line -match "UPROPERTY\(\)")
        {
            $flags = ""
            if ($isPublic)
            {
                $flags = AddFlag -currentFlag $flags -newFlag "Public"
            }
            else
            {
                $flags = AddFlag -currentFlag $flags -newFlag "NoPublic"
            }
            if ($line.Contains("static"))
            {
                $flags = AddFlag -currentFlag $flags -newFlag "Static"
            }
            $isPointer = $line.Contains("*")
    
            $field = ReplaceStr -str $line -toReplace @("inline", "const", "static", "constexpr", "UPROPERTY()") -to ""
            $field = $field.TrimStart()
            $field = $field.Substring($field.IndexOf(' ') + 1)
            $field = $field.Substring(0, $field.IndexOf(' ')).Trim()
    
            $result = ""
            if ($isPointer)
            {
                $result = "REGISTER_FIELD($field, $field, $flags)"
            }
            else
            {
                $result = "REGISTER_FIELD($field, &$field, $flags)"
            }
            
            $file = (Get-Content $includePath) -as [Collections.ArrayList]
            if ($fileContent[$i + 1] -match "REGISTER_FIELD")
            {
                $file.RemoveAt($i + 1)
                $file.Insert($i + 1, $result)
            }
            else
            {
                $file.Insert($i + $indexFile + 1, $result)
                $indexFile = $indexFile + 1
            }
            $file | Set-Content $includePath
        }
    
        if ($line -match "REGISTER_FIELD" -and $fileContent[$i - 1] -notmatch "UPROPERTY")
        {
            $file = (Get-Content $includePath) -as [Collections.ArrayList]
            $file.RemoveAt($i)
            $file | Set-Content $includePath
        }
    }
}