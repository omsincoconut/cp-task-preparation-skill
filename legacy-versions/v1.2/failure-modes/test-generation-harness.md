# Test-Generation Harness Failure Modes

Use this file for mistakes in constructing, validating, benchmarking, promoting, or explaining testcases.

## Failure Mode: Validator-Passing Is Treated As Statement-Valid

- Wrong assumption: If a testcase passes the local validator or public grader, it satisfies the full statement.
- Code/editorial smell: The validator omits a semantic statement constraint, such as requiring every per-node list size `S_i >= 1`.
- Small counterexample shape: A generated case uses an omitted forbidden value and appears valid to the local validator.
- Scalable stress shape: A whole stress family depends on the omitted constraint, so fixing it changes runtime or correctness behavior.
- Validation guardrails: Build a source-of-truth table from statement, validator, grader, and solution constants. Run an independent statement-level scan before promotion.
- Related files: `../references/statement-validation.md`.

## Failure Mode: Unread Stdout Pipe Creates False TLE

- Wrong assumption: A process that times out under a monitoring wrapper is computationally too slow.
- Code/editorial smell: The wrapper starts the solution with stdout piped but does not continuously drain the pipe, so large output blocks the process.
- Small counterexample shape: High-output control case with trivial computation also appears slow or stuck.
- Scalable stress shape: Any valid case with many output lines can falsely TLE under the bad harness.
- Validation guardrails: Benchmark large-output programs with direct file redirection: `solution < case.in > case.out 2> case.err`.
- Related files: `../references/countertest-and-benchmarking.md`.

## Failure Mode: Stress Family Depends On An Invalid Loophole

- Wrong assumption: Fixing an invalid field is a local repair that preserves the stress mechanism.
- Code/editorial smell: The strongest tests rely on values outside statement constraints, and replacing them changes total payload, shape, branch classification, or output behavior.
- Small counterexample shape: One invalid file becomes legal after patching but no longer triggers the intended path.
- Scalable stress shape: Regenerate the family from scratch under all statement constraints and compare the mechanism summaries.
- Validation guardrails: Do not hand-patch promoted tests unless the generator and logs are updated. Mark old results invalid.
- Related files: `../references/testcase-generation.md`.

## Failure Mode: Top Stress Set Has One Nature But Is Reported As Broad

- Wrong assumption: The top five slowest files automatically represent diverse coverage.
- Code/editorial smell: All top cases share the same tree shape, bottleneck, query pattern, or output-volume cause.
- Small counterexample shape: Two almost identical parameter variants occupy several top slots.
- Scalable stress shape: Keep the top raw performers but also generate mechanism-diverse runners-up for coverage reporting.
- Validation guardrails: State when top cases are all from one family. Do not imply broad adversarial coverage without different mechanisms.
- Related files: `../templates/result_top5.md`.

## Failure Mode: Missing Dry-Run Checker For Internal Order

- Wrong assumption: The generated input shape directly implies the internal query order or group assignment.
- Code/editorial smell: Tests target sorted/offline behavior, but logs only show raw input properties.
- Small counterexample shape: A miniature case where manual sorted order differs from input order.
- Scalable stress shape: Generate the full case and emit a summary of block IDs, first sorted classes, branch counts, and expensive-operation estimates.
- Validation guardrails: Preserve dry-run summaries next to validation and benchmark logs.
- Related files: `offline-queries.md`, `../templates/test_generation_notes.md`.

## Failure Mode: Editorial Intent And Generator Intent Are Not Cross-Checked

- Wrong assumption: Reading either the official editorial or the local generator names is enough to understand coverage.
- Code/editorial smell: The editorial emphasizes a failure mechanism such as fixed popcount, endpoint deletion, or greedy replacement, but the generated tests are only random or only sample-sized.
- Small counterexample shape: One hand-built test from the editorial's key branch that no existing generator family names directly.
- Scalable stress shape: Add a dedicated generator family whose parameters expose the editorial mechanism at subtask and full limits.
- Validation guardrails: For each promoted family, record the editorial mechanism, generator source, seed/parameters, and expected solution verdicts.
- Related files: `../templates/test_generation_notes.md`.

## Failure Mode: Subtask Score State Is Confused With Final Correctness

- Wrong assumption: Passing a partial-scoring halt state, constrained subtask, or sample-grader behavior means the full task is solved.
- Code/editorial smell: The package has partial and full constructive strategies, custom scorer fractions, or overlapping scorer groups, but the test documentation records only pass/fail.
- Small counterexample shape: A case that receives partial score by halting in an accepted partial location but fails the full-score condition.
- Scalable stress shape: Cover every scorer fraction or subtask group with tests that distinguish partial from full behavior.
- Validation guardrails: Document scorer-code behavior separately from `scorer.txt`; do not use partial solutions as full model solutions.
- Related files: `constructive.md`.
