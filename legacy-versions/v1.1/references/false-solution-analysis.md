# False-Solution Analysis

Use this reference to turn wrong, partial, and slow solutions into targeted tests.

## Classification

- Accepted/model: candidate oracle if trusted and full.
- Brute: oracle for small constraints.
- TLE/slow: useful for max-size and complexity tests.
- Wrong answer: useful for adversarial semantic cases.
- Partial/subtask: useful for subtask boundaries, not full outputs.
- Unknown: inspect before use; otherwise document uncertainty.

## Workflow

1. Read `.desc`, metadata, filenames, and comments for verdict evidence.
2. Compare wrong solution logic with the model or editorial idea.
3. Identify the false invariant, missing case, overflow, complexity flaw, or protocol mistake.
4. Determine the intended verdict for every relevant subtask: AC, WA, TLE, partial, or not applicable.
5. Construct the smallest failing case if possible, but make it as strong as the subtask constraints allow.
6. Prefer countertests that make the wrong solution fail multiple subtasks or also break other plausible wrong solutions.
7. Generalize into a generator family only when the concrete case is not enough.
8. Add a stress command that compares model and brute, then checks the wrong solution fails when useful.
9. Record the failure mode and subtask-verdict matrix in `wrong_solution.md` or testcase documentation.

## Failure Modes To Target

- Endpoint versus middle cases.
- Tie handling.
- Duplicate values.
- Overflow and signedness.
- Greedy choice ordering.
- Parity and modulo edge cases.
- All-equal or single-different cases.
- Fixed-popcount and high-bit boundaries.
- Graph loops, disconnected components, and color-state traps.
- Incorrect interactor assumptions or query counts.

## Use Of Accepted Submissions

Accepted/local submissions are references for algorithmic diversity and stress comparison. Do not learn package structure or naming conventions from them.
