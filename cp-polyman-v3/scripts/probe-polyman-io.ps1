[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$Workspace,

    [Parameter(Mandatory = $true)]
    [string]$Testset,

    [Parameter(Mandatory = $true)]
    [ValidateRange(1, [int]::MaxValue)]
    [int]$Index,

    [Parameter(Mandatory = $true)]
    [string]$Solution
)

$ErrorActionPreference = 'Stop'
$workspacePath = (Resolve-Path -LiteralPath $Workspace).Path
$configPath = Join-Path $workspacePath 'Config.json'

if (-not (Test-Path -LiteralPath $configPath)) {
    throw "Config.json was not found in '$workspacePath'."
}
if (-not (Get-Command polyman -ErrorAction SilentlyContinue)) {
    throw 'polyman is not available on PATH.'
}

function Invoke-Polyman {
    param([string[]]$Arguments)

    & polyman @Arguments
    if ($LASTEXITCODE -ne 0) {
        throw "polyman $($Arguments -join ' ') failed with exit code $LASTEXITCODE."
    }
}

Push-Location -LiteralPath $workspacePath
try {
    Invoke-Polyman @('--version')
    Invoke-Polyman @('generate', '--testset', $Testset, '--index', $Index)

    $testsetDir = Join-Path -Path (Join-Path -Path $workspacePath -ChildPath 'testsets') -ChildPath $Testset
    $testPath = Join-Path -Path $testsetDir -ChildPath ("test$Index.txt")
    if (-not (Test-Path -LiteralPath $testPath)) {
        throw "Generated test was not found at '$testPath'."
    }

    $bytes = [System.IO.File]::ReadAllBytes($testPath)
    $crlf = 0
    $lf = 0
    for ($i = 0; $i -lt $bytes.Length; ++$i) {
        if ($bytes[$i] -ne 10) {
            continue
        }
        if ($i -gt 0 -and $bytes[$i - 1] -eq 13) {
            ++$crlf
        } else {
            ++$lf
        }
    }
    Write-Output "Materialized test: $testPath"
    Write-Output "Line endings: CRLF=$crlf LF=$lf bytes=$($bytes.Length)"

    Invoke-Polyman @('validate', '--testset', $Testset, '--index', $Index)
    Invoke-Polyman @('run', $Solution, '--testset', $Testset, '--index', $Index)
} finally {
    Pop-Location
}
