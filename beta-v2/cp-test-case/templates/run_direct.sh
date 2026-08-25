#!/usr/bin/env bash
set -euo pipefail

solution="${1:?usage: run_direct.sh SOLUTION CASE [TL_SECONDS] [ML_MB]}"
case_file="${2:?usage: run_direct.sh SOLUTION CASE [TL_SECONDS] [ML_MB]}"
tl="${3:-60}"
ml_mb="${4:-1024}"

base="${case_file%.*}"
out="${base}.out"
err="${base}.err"
log="${base}.log"

rm -f "$out" "$err" "$log"

status="completed"
exit_code=0
start_ns="$(date +%s%N)"

if command -v /usr/bin/time >/dev/null 2>&1; then
  if ! timeout "$tl" /usr/bin/time -f "PeakKB: %M" -o "${log}.time" "$solution" < "$case_file" > "$out" 2> "$err"; then
    exit_code=$?
    if [ "$exit_code" -eq 124 ]; then
      status="TLE"
    else
      status="RE"
    fi
  fi
  peak_kb="$(awk '/PeakKB:/ {print $2}' "${log}.time" 2>/dev/null || true)"
else
  if ! timeout "$tl" "$solution" < "$case_file" > "$out" 2> "$err"; then
    exit_code=$?
    if [ "$exit_code" -eq 124 ]; then
      status="TLE"
    else
      status="RE"
    fi
  fi
  peak_kb=""
fi

end_ns="$(date +%s%N)"
elapsed="$(awk -v s="$start_ns" -v e="$end_ns" 'BEGIN { printf "%.3f", (e-s)/1000000000 }')"
out_bytes="$(wc -c < "$out" 2>/dev/null || echo 0)"
out_lines="$(wc -l < "$out" 2>/dev/null || echo 0)"
err_bytes="$(wc -c < "$err" 2>/dev/null || echo 0)"

{
  echo "Case: $case_file"
  echo "Command: $solution < $case_file > $out 2> $err"
  echo "TimeLimitSeconds: $tl"
  echo "MemoryLimitMB: $ml_mb"
  echo "Status: $status"
  echo "ExitCode: $exit_code"
  echo "TimeSeconds: $elapsed"
  echo "PeakKB: $peak_kb"
  echo "OutputBytes: $out_bytes"
  echo "OutputLines: $out_lines"
  echo "ErrBytes: $err_bytes"
} > "$log"

cat "$log"
