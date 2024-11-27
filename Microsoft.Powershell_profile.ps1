Write-Host "loading whitelies125 config.(~\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1)"

#oh-my-posh init pwsh --config 'C:\Users\whitelies125\Documents\WindowsPowerShell\catppuccin.omp.json' | Invoke-Expression
#Set-PSReadLineOption -Colors @{Number = "$([char]0x1b)[93m"}

function rewrite_cd (
    [Parameter(Mandatory=$true)]
    [string] $string
){
    $exe_path = "fod"
    if (-not (Get-Command $exe_path -ErrorAction SilentlyContinue)) {
        Write-Host "fod.exe not found. make sure fod.exe in your system environment path."
        Set-Location -Path $string
        return
    }
    $cmd = "& '$exe_path' '$string'"
    Invoke-Expression $cmd -OutVariable stdOut | Out-Null
    if($LASTEXITCODE -eq 0) {
        Set-Location -Path $stdOut[0]
        Write-Host (Get-Location).path
    } else {
        Set-Location -Path $string
    }
}

Set-Alias -Name:"cd" -Value:"rewrite_cd" -Option AllScope

Write-Host "load whitelies125 config sucess."
