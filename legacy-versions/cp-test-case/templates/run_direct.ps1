param(
    [Parameter(Mandatory = $true)][string]$Solution,
    [Parameter(Mandatory = $true)][string]$Case,
    [int]$TimeLimitSeconds = 60,
    [int]$MemoryLimitMB = 1024
)

$ErrorActionPreference = 'Stop'

$caseItem = Get-Item -LiteralPath $Case
$base = Join-Path $caseItem.DirectoryName $caseItem.BaseName
$outPath = "$base.out"
$errPath = "$base.err"
$logPath = "$base.log"
Remove-Item -LiteralPath $outPath, $errPath, $logPath -ErrorAction SilentlyContinue

$cmdLine = '/c "' + (Resolve-Path $Solution) + ' < ' + $caseItem.FullName + ' > ' + $outPath + ' 2> ' + $errPath + '"'
$psi = [System.Diagnostics.ProcessStartInfo]::new()
$psi.FileName = 'cmd.exe'
$psi.Arguments = $cmdLine
$psi.WorkingDirectory = (Get-Location).Path
$psi.UseShellExecute = $false

$processName = [System.IO.Path]::GetFileNameWithoutExtension($Solution)
$p = [System.Diagnostics.Process]::new()
$p.StartInfo = $psi
$null = $p.Start()

$sw = [System.Diagnostics.Stopwatch]::StartNew()
$peak = 0L
$status = 'completed'
while (-not $p.HasExited) {
    $sum = 0L
    try {
        $p.Refresh()
        $sum += $p.WorkingSet64
    } catch {}
    try {
        Get-Process $processName -ErrorAction SilentlyContinue | ForEach-Object {
            $sum += $_.WorkingSet64
        }
    } catch {}
    if ($sum -gt $peak) { $peak = $sum }
    if ($sw.Elapsed.TotalSeconds -ge $TimeLimitSeconds) {
        $status = 'TLE'
        taskkill /PID $p.Id /T /F | Out-Null
        break
    }
    if ($peak -gt $MemoryLimitMB * 1MB) {
        $status = 'MLE'
        taskkill /PID $p.Id /T /F | Out-Null
        break
    }
    Start-Sleep -Milliseconds 20
}
$p.WaitForExit()
$sw.Stop()

$exitCode = if ($status -eq 'completed') { $p.ExitCode } else { $null }
if ($status -eq 'completed' -and $exitCode -ne 0) { $status = 'RE' }

$outBytes = (Get-Item -LiteralPath $outPath -ErrorAction SilentlyContinue).Length
$errBytes = (Get-Item -LiteralPath $errPath -ErrorAction SilentlyContinue).Length
$outLines = if ($outBytes -gt 0) { (Get-Content -LiteralPath $outPath | Measure-Object -Line).Lines } else { 0 }
$sec = [Math]::Round($sw.Elapsed.TotalSeconds, 3)
$mb = [Math]::Round($peak / 1MB, 2)

[System.IO.File]::WriteAllLines($logPath, @(
    "Case: $($caseItem.FullName)",
    'Direct redirection benchmark',
    "TimeLimitSeconds: $TimeLimitSeconds",
    "MemoryLimitMB: $MemoryLimitMB",
    "Status: $status",
    "ExitCode: $exitCode",
    "TimeSeconds: $sec",
    "PeakWorkingSetTreeMB: $mb",
    "OutputBytes: $outBytes",
    "OutputLines: $outLines",
    "ErrBytes: $errBytes"
))

Get-Content -LiteralPath $logPath
