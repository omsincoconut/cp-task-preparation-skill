# Benchmark Harness Checklist

- Run static TL/ML analysis before timing.
- Use direct file redirection for programs with nontrivial output.
- Do not redirect stdout or stderr to unread pipes.
- Use the same compiled candidate and grader path for all compared cases.
- Record time limit, memory limit, elapsed wall time, peak memory, exit code, output bytes, output lines, and stderr bytes.
- Separate harness failures from solution failures.
- Treat local-only effects as diagnostics unless they match the official judging environment.
- Preserve logs next to the input and output files.
