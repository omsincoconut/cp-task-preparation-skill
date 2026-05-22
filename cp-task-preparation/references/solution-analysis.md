# Solution Analysis

Use this reference to classify model, brute, partial, wrong, slow, borderline, and contestant-template solutions, then turn that classification into subtask-verdict expectations.

## Classification

- Accepted/model: candidate oracle if trusted and full.
- Borderline accepted: correct approach with risky constants, memory layout, or implementation choices.
- Brute: oracle for small constraints.
- TLE/slow: useful for max-size and complexity tests.
- Wrong answer: useful for adversarial semantic cases.
- Partial/subtask: useful for subtask boundaries, not full outputs.
- Unknown: inspect before use; otherwise document uncertainty.

## Workflow

1. Read metadata, filenames, `.desc` files, comments, and source behavior for verdict evidence.
2. Compare non-model solutions with the model, editorial idea, or brute oracle.
3. Identify the false invariant, missing case, overflow, complexity flaw, protocol mistake, unsupported subtask, or performance fragility.
4. Determine the expected verdict for every relevant subtask: AC, WA, TLE, MLE, RE, partial, or not applicable.
5. Decide whether the flaw is semantic, complexity-based, resource-based, protocol-based, or local-only.
6. Route semantic and complexity flaws to `references/testcase-generation.md` and relevant files from `failure-modes/INDEX.md`.
7. Record the failure mode, proof or complexity explanation, validity checks, and subtask-verdict matrix in `wrong_solution.md` or testcase documentation.

## Performance Robustness

- Do not assume a correct asymptotic is automatically safe. Check slower implementations of the same asymptotic class for heavy constants, cache-unfriendly layouts, repeated allocations, expensive STL usage, copying, recursion overhead, comparator cost, iterator patterns, branch-heavy code, and poor hash behavior.
- Do not assume a bad asymptotic is automatically TLE. Consider realistic optimization attempts such as pragmas, fast I/O, hand-written arrays, cache-aware layouts, custom allocators, bitset tricks, branchless loops, loop unrolling, and avoiding STL.
- Benchmark robust accepted, borderline accepted, optimized slow, brute, wrong, partial, and contestant-template implementations when available. If a class is unavailable, document why.
- Expected verdict matrices are claims. Validate them empirically against important non-model implementations and revise either tests, TL/ML, or the matrix when measurements disagree.

## Subtask Reasoning

- Make a wrong solution fail in every applicable subtask the official constraints allow.
- If the bug can appear in a smaller subtask, include or request a small-subtask countertest instead of relying only on full-constraint tests.
- If a subtask's constraints make the bug impossible, document that reason.
- Do not assume small subtasks should have weak tests.

## Use Of Accepted Submissions

Accepted/local submissions are references for algorithmic diversity and stress comparison. Do not learn package structure or naming conventions from them.
