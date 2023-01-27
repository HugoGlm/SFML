Param(
    [parameter()]
    [String]$path
)

powershell.exe -ExecutionPolicy Bypass -File ReflectionProperty.ps1 -path $path
powershell.exe -ExecutionPolicy Bypass -File ReflectionFunction.ps1 -path $path