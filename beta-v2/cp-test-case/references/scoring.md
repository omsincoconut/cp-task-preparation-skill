# Scoring and Subtasks

Use scoring information to understand which testcase groups must separate which classes of solutions.

## Roles

- Subtask/group definitions describe which tests contribute to which portions of the score.
- A checker, grader, or protocol may produce per-test outcomes or partial credit.
- The package platform may aggregate those outcomes differently; keep platform syntax outside this skill.

## Test-Shaping Rules

- Preserve overlapping subtask membership when a testcase satisfies several promises.
- For each subtask, identify which wrong/partial/slow solutions should pass or fail and why.
- Use the strongest legal construction inside the subtask when a separation is intended.
- Do not flatten protocol-driven or fractional scoring into a simpler model if that would change expected behavior.

## Expected Outputs

Generate outputs only when a trusted oracle exists:

- full model solution for ordinary batch-style outputs;
- trusted grader plus full model for library tasks;
- official answer files or another confirmed oracle path.

Do not use partial, subtask-only, wrong, or unknown solutions as full-output oracles.
