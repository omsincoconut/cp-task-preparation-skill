# Benchmarking

Use this reference for runtime, memory, output-size, and TL/ML claims.

## Direct-Redirection Rule

For large outputs, use direct file redirection:

```text
solution < case.in > case.out 2> case.err
```

Avoid harnesses that redirect stdout or stderr to unread pipes. They can block the child process and create false TLEs.

## Minimum Log

Preserve:

- case name and command shape;
- time limit and memory limit;
- status: completed, WA, RE, TLE, MLE, local artifact, or stress only;
- elapsed wall time;
- exit code;
- peak memory if measurable;
- output bytes and lines;
- stderr bytes;
- validator result and statement-scan result.

## Benchmark Discipline

- Run static TL/ML analysis before timing.
- Document where TL/ML are configured, and avoid scattering time or memory limits through unrelated files.
- After changing constraints, regenerate tests and rerun the benchmark/verdict matrix before reusing old TL/ML assumptions.
- Unless explicitly overridden, terminate presumed-TL benchmark runs at $3 \times$ the official time limit and presumed-ML runs at $2 \times$ the official memory limit. This is benchmark management, not an official verdict guarantee.
- Use the same compiled candidate and grader path for compared cases.
- Keep small oracle-backed analogues for large stress cases when possible.
- Do not report local-only effects as official judge failures unless the local environment matches the judge-relevant behavior.
- Preserve logs near the promoted inputs and outputs.
- Benchmark more than the ideal reference implementation when performance margins matter: robust accepted, borderline accepted, optimized slow, brute, wrong, partial, and contestant-template implementations when available.
- Compare same-asymptotic variants for constant-factor risk: allocations, cache locality, STL/container overhead, copying, comparators, recursion, hash behavior, branch-heavy code, and iterator patterns.
- For slow/TLE claims, account for realistic microoptimized variants before treating the countertest as robust.
- Check whether the local grader enforces TLE/MLE or only reports elapsed time and memory. If it only reports, document that limitation or add post-run classification when appropriate.
- When a benchmark cutoff is used, record the cutoff and distinguish preemptive timeout/memory termination from post-run verdict classification and from confidently established official TLE/MLE claims.
- Treat runtime margins as evidence, not proof: if an optimized slow solution passes unexpectedly, strengthen the bottleneck-targeting tests, revise TL only with model margin, or update the intended verdict matrix.
