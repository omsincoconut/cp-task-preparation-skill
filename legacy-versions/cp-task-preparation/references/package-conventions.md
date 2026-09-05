# Package Conventions

Use this reference to decide file roles, target layout, folder organization, and test naming. Do not infer conventions from accepted-submission folders or arbitrary contest directories.

## Source Priority

- Use convention packages for package shape: `aplusb`, `rolling`, `meltdown`.
- Use Codeforces packages for testcase reasoning, generator intent, stress style, and false-solution analysis.
- Treat a package as mixed only when there is explicit evidence of multiple platforms.
- Preserve unclear source folders as source material, not as target conventions.

## Target Folders

```text
polygon/  Polygon package materials.
cms/      CMS package materials.
local/    Local grader package.
markdowns/ Statements, editorials, summaries, testcase notes, run results, verification notes, and wrong-solution notes.
tmp/      Files irrelevant to the folders above.
```

Keep `polygon/`, `cms/`, and `local/` separate when more than one exists. Shared markdown deliverables belong in `markdowns/`; scratch artifacts and temporary logs belong in `tmp/` unless a reference or checklist says a log must be preserved next to a promoted test. Remove obsolete binaries, comparison outputs, and benchmark leftovers from `tmp/` before final delivery.

For packages with validators or generators, prefer a single canonical constraints header such as `polygon/constraints.h` for global limits, subtask thresholds, and TL/ML constants. Platform metadata may mirror these values, but generators, validators, and local graders should include or explicitly derive from the canonical owner where practical. After changing canonical constraints, audit mirrored limits in XML, statements, graders, scripts, and docs for stale metadata drift.

## Platform Layout Patterns

Polygon-oriented:

```text
polygon/
  problem.xml
  constraints.h
  validator.cpp
  checker.cpp
  interactor.cpp
  testlib.h
  generators/
  scripts/
  tests/
  scorer.txt
```

CMS-oriented:

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

Local-grader packages:

```text
local/
  task.cpp
  task.h
  grader.cpp
  mass_grader.cpp
  compile_and_run.cmd
  tests/
```

See `references/local-grader.md` for the exact local grader contract.

## Test Naming

- Polygon default: `01` and `01.a`, then `02` and `02.a`.
- CMS default: `001.in` and `001.out`, then `002.in`, `002.out`.
- If existing Polygon tests already use IDs such as `001`, preserve them unless normalizing is explicitly part of the task.
- When renaming tests, record the old-to-new mapping in cleaning notes.

## File Roles

- Model solution: trusted full solution used for answers and stress comparison.
- Brute solution: slow but clear oracle for small cases.
- Subtask solution: correct only for documented constraints.
- Partial solution: useful evidence, not a full oracle.
- Wrong solution: rejected or intentionally flawed implementation for adversarial tests.
- Contestant stub: starter implementation, not an official solution.
- CMS/local `task.cpp`: contestant template or stub for library tasks; do not place model, hidden, or editorial logic there.

## Non-Inference Rules

- Do not create a checker because a Polygon package often has `checker.cpp`.
- Do not infer custom scoring from the presence of a checker.
- Do not infer every CMS task has custom scoring.
- Do not infer every library task needs a grader unless the interface requires one.
- Do not infer missing full generated tests in Polygon packages means the package is broken; generators and scripts may be the source of truth.
