param(
    [Parameter()]
    [string]$path
)

Get-ChildItem $path -Recurse -Filter *.h | 
    Foreach-Object{
        $fullpath = $_.FullName
        $className = (Get-Item $fullpath).BaseName
        $includePath = $fullPath.Replace($path, "")
        $includePath = $includePath.Substring(0, $includePath.Length)
        $includePath = $includePath.Replace("", "/")

        $Assemblie = (Get-Content $assembliePath) -as [Collections.ArrayList]
        $size = $Assemblie.Count
        $namespace = ""

        $fileContent = (Get-Content $fullPath) -as [Collections.ArrayList]
        for ($i = 0; $i -lt $fileContent.Count; $i = $i + 1)
        {
            $line = $fileContent[$i]
            if ($namespace -eq "" -and $line -match "namespace")
            {
                $namespace = "using " + $line + ";"
            }

            if ($line -match "UCLASS()")
            {
                
            }
        }
    }