# Package Conventions

Use this reference to decide file roles and target layout. Do not infer conventions from accepted-submission folders or arbitrary contest directories.

## Source Priority

- Use convention packages for package shape: `aplusb`, `rolling`, `meltdown`.
- Use Codeforces packages for testcase reasoning, generator intent, stress style, and false-solution analysis.
- Treat a package as mixed only when there is explicit evidence of multiple platforms.
- Preserve unclear source folders as source material, not as target conventions.

## Target Layout Patterns

Polygon-oriented:

```text
polygon/
  problem.xml
  validator.cpp
  checker.cpp
  interactor.cpp
  testlib.h
  generators/
  scripts/
  tests/
  scorer.txt
solutions/
statement.md
editorial.md
```

CMS-oriented:

```text
cms/
  grader.cpp
  task.h
  task.cpp
  scorer.cpp
  scorer.txt
  tests/
solutions/
statement.md
editorial.md
```

Mixed packages keep `polygon/`, `cms/`, and `solutions/` separate. Shared statements and editorials can live at the package root unless the user requires platform-specific statements.

## Test Naming

- Polygon default: `01` and `01.a`, then `02` and `02.a`.
- CMS default: `001.in` and `001.out`, then `002.in` and `002.out`.
- If existing Polygon tests already use IDs such as `001`, preserve them unless normalizing is explicitly part of the task.
- When renaming tests, record the old-to-new mapping in cleaning notes.

## File Roles

- Model solution: trusted full solution used for answers and stress comparison.
- Brute solution: slow but clear oracle for small cases.
- Subtask solution: correct only for documented constraints.
- Partial solution: useful evidence, not a full oracle.
- Wrong solution: rejected or intentionally flawed implementation for adversarial tests.
- Contestant stub: starter implementation, not an official solution.

## Non-Inference Rules

- Do not create a checker because a Polygon package often has `checker.cpp`.
- Do not infer custom scoring from the presence of a checker.
- Do not infer every CMS task has custom scoring.
- Do not infer every library task needs a grader unless the interface requires one.
- Do not infer missing full generated tests in Polygon packages means the package is broken; generators and scripts may be the source of truth.
