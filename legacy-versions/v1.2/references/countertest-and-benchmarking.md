# Countertest And Benchmarking

Use this reference when testing a claimed solution, constructing countercases, or reporting TL/ML behavior.

## Order Of Work

1. Read the statement, resource limits, grader/parser, validator, and candidate solution.
2. Do static TL/ML analysis before empirical runs.
3. Decide whether the target is correctness, TLE, MLE, RE, or tight-but-valid stress.
4. Construct a small explainable case first, then scale only when the failure is understood.
5. Validate the input against both the validator and statement-specific checks.
6. Benchmark with a trustworthy harness and preserve logs.
7. Classify the result conservatively.

## Direct-Redirection Benchmarking

For large outputs, use direct file redirection:

```text
solution < case.in > case.out 2> case.err
```

Avoid harnesses that redirect stdout to an unread pipe. They can block the child process and create false TLEs.

Log at minimum:

- case name and command shape;
- time limit and memory limit;
- status: completed, WA, RE, TLE, MLE, local artifact, or stress only;
- elapsed wall time;
- exit code;
- peak memory if measurable;
- output bytes and lines;
- stderr bytes;
- validator result and statement-scan result.

## Classification

- `WA`: trusted oracle or checker proves the answer invalid.
- `RE`: nonzero exit or crash under judge-relevant conditions.
- `TLE`: direct-redirection run exceeds the intended cap under comparable judge assumptions.
- `MLE`: memory exceeds the intended cap under comparable judge assumptions.
- `local artifact`: failure depends on a local condition absent from the judge, such as stack limits, shell behavior, or pipe blocking.
- `stress only`: valid case is slow or informative but does not prove a judge failure.

If no valid counter is found, write that directly and report the strongest stress cases with their limits and residual uncertainty.
