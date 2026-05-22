# Local Grader

Use this reference for the `local/` package.

## Contents

`local/` contains the local grader package:

```text
local/
  task.cpp
  task.h
  grader.cpp
  mass_grader.cpp
  compile_and_run.cmd
  tests/
```

`local/task.cpp`, `local/task.h`, and `local/grader.cpp` do the same jobs as their CMS package equivalents. Once `local/task.cpp` exists and may have been externally modified, treat it as user-owned contestant code: read it when needed, but do not overwrite it.

## Compile Script

`local/compile_and_run.cmd` compiles `task.cpp` together with `mass_grader.cpp`, then executes mass grading.

Smoke-test `compile_and_run.cmd` after editing it. Any generated executable should be placed in an expected scratch location or removed after the run according to package hygiene rules.

## Mass Grader

`local/mass_grader.cpp`, when compiled together with `task.cpp`, runs `task.cpp` against all local test cases and prints exactly:

```text
Number of tests: [TEST_COUNT]
Number of subtasks: [SUBTASK_COUNT]
Test 1: [VERDICT: AC,WA,TLE,MLE,...] [TIME_USED_SECONDS] [MEMORY_USE_MB]
Test 2: [VERDICT: AC,WA,TLE,MLE,...] [TIME_USED_SECONDS] [MEMORY_USE_MB]
...
Subtask 1: [SCORE]
Subtask 2: [SCORE]
...
Total score: [TOTAL_SCORE]
```

Keep this output contract verbatim when creating or reviewing local grader packages.

When the package has centralized constraints, local grader subtask predicates and TL classification should include or explicitly mirror that owner. Keep named constants for thresholds and time limits so constraint scaling does not leave stale local grading behavior behind.
