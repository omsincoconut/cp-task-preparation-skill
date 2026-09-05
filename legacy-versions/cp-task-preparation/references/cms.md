# CMS Reference

Use this reference for CMS or OI-style cleaned packages, especially grader-based and library tasks. Use `references/scoring.md` for scoring details.

## Target Shape

```text
cms/
  grader.cpp
  task.h
  task.cpp
  solutions/
  manual.pdf
  scorer.cpp
  scorer.txt
  tests/
```

Not every CMS task has every file. Preserve only confirmed components.

## Tests

- Use `001.in`, `001.out`, then `002.in`, `002.out`.
- If original names encode subtasks, sort them deterministically and record the mapping.
- Keep outputs only when they are confirmed official or regenerated through a trusted grader/model path.

## Grader-Based Tasks

- A grader defines the contestant interface and I/O protocol.
- A sample grader may be for contestants and may differ from the official CMS grader.
- Headers declare contestant functions; `task.cpp` is the contestant template/stub, not a model solution or hidden implementation.
- Put official/reference solutions under solution locations such as `cms/solutions/`, and compile them with the grader only for answer generation or verification.
- For library tasks, a model solution may need to be compiled with a grader to generate outputs.
- Statements should focus on the function contract, parameters, return value, constraints, and examples as function calls or values.
- Do not describe stdin/stdout interaction in the public statement unless the CMS task is explicitly presented as a batch task.
- Official and contestant-facing solution files should include the task header and implement the required function without `main`; keep graders and stubs in their own files.
- Sample graders and task headers should be minimal interface files: include only required standard headers, qualify standard-library names with `std::`, and avoid `bits/stdc++.h`, `using namespace std`, typedefs, and type aliases.

## Batch Custom Scoring

- For CMS batch tasks with custom scoring, name the checker source `checker.cpp`.

## Uncertainty

If the package lacks a full model solution, say so. Subtask or partial solutions can still be preserved, but must not be used as full oracles.
