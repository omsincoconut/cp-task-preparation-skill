# Countertest Methodology

Use this reference when constructing or promoting a counterexample, including WA, TLE, MLE, RE, and stress-only findings. Use `references/benchmarking.md` for timing and memory measurement mechanics.

## Promotion Order

1. State the claim being tested.
2. Do static analysis before empirical runs.
3. Decide whether the target is correctness, TLE, MLE, RE, or tight-but-valid stress.
4. Construct a small explainable case first.
5. Validate the input against the validator and statement-specific checks.
6. Preserve the formal, static, or complexity reason behind the result.
7. Classify the outcome conservatively.

## Validity Rules

- Countertests must remain legal after every statement constraint is enforced.
- If a stress family depends on a missing validator check or invalid loophole, discard or regenerate it under the real constraints.
- If fixing invalid fields changes the asymptotic or empirical behavior, rerun the search from scratch and invalidate earlier logs.
- Separate official counterexamples from local-environment artifacts such as stack-limit crashes or shell behavior.
- For TLE/MLE countertests, consider optimized or constant-factor-improved variants before overclaiming robustness. If only the unoptimized version fails, classify the case narrowly or strengthen the bottleneck mechanism.

## Classification

- `WA`: trusted oracle or checker proves the answer invalid.
- `RE`: nonzero exit or crash under judge-relevant conditions.
- `TLE`: benchmark evidence exceeds the intended cap under comparable judge assumptions.
- `MLE`: memory evidence exceeds the intended cap under comparable judge assumptions.
- `local artifact`: failure depends on a local condition absent from the judge.
- `stress only`: valid case is slow or informative but does not prove a judge failure.

If no valid counter is found, write that directly and report the strongest stress cases with their limits and residual uncertainty.
