# CMS Reference

Use for CMS or OI-style cleaned packages, especially grader-based and custom-scored tasks.

## Target Shape

```text
cms/
  grader.cpp
  task.h
  task.cpp
  manual.pdf
  scorer.cpp
  scorer.txt
  tests/
solutions/
statement.md
editorial.md
```

Not every CMS task has every file. Preserve only confirmed components.

## Tests

- Use `001.in`, `001.out`, then `002.in`, `002.out`.
- If original names encode subtasks, sort them deterministically and record the mapping.
- Keep outputs only when they are confirmed official or regenerated through a trusted grader/model path.

## Grader-Based Tasks

- A grader defines the contestant interface and I/O protocol.
- A sample grader may be for contestants and may differ from the official CMS grader.
- Headers declare contestant functions; stubs are starter files, not solutions.
- For library tasks, a model solution may need to be compiled with a grader to generate outputs.
- Statements should focus on the function contract, parameters, return value, constraints, and examples as function calls or values.
- Do not describe stdin/stdout interaction in the public statement unless the CMS task is explicitly presented as a batch task.
- Official and contestant-facing solution files should include the task header and implement the required function without `main`; keep graders and stubs in their own files.

## Custom Scoring

- `scorer.txt` can summarize visible groups and points.
- `scorer.cpp` or a CMS checker may implement the real per-test score protocol.
- If the scorer maps grader exit values or protocol tokens to fractions, document that explicitly.
- Do not flatten partial scoring into regex groups if that would lose behavior.
- If tests satisfy multiple subtasks, list them in every applicable scorer group instead of assigning each test only to the smallest or earliest matching group.

## Uncertainty

If the package lacks a full model solution, say so. Subtask or partial solutions can still be preserved, but must not be used as full oracles.
