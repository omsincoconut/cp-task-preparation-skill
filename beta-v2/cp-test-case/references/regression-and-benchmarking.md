# Test Suite Regression

Use this after changing generators, constraints, promoted tests, oracle code, or testcase ordering.

## Regression principle

A testcase-suite change is not complete until previously established evidence is rechecked. Do not assume that adding a stronger case cannot break validity, subtask membership, expected outputs, or runtime conclusions elsewhere.

## Checks

- Revalidate every changed or regenerated promoted input against the semantic validity model.
- Regenerate expected outputs only through the trusted oracle path when inputs changed.
- Rerun the known accepted/model, wrong, partial, slow, and borderline implementations relevant to changed families.
- Recheck the expected solution-by-group verdict matrix.
- Re-run performance measurements when test scale/distribution, compiler settings, TL/ML assumptions, or generator behavior changed.
- Preserve seeds, parameters, logs, and the reason for each promoted family so results are reproducible.
- If a previously targeted wrong/slow solution now passes, either restore the separation or update the claim; do not leave stale documentation.

Platform-specific commands and package integration remain the responsibility of `cp-polygon` or `cp-cms`.
