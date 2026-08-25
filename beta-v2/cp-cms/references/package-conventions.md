# CMS Package Conventions

CMS separates the judging data model/task type from the filesystem format used by task authors. Do not assume one universal source package layout.

## Priority

1. User/contest repository convention.
2. Explicit loader/import format requirements.
3. Existing package structure when repairing a task.
4. A cleaned internal layout only when the user wants one and no importer shape is required.

## Cleaned Internal Layout

For a library-style cleaned workspace, a layout such as the following is reasonable when it matches the task:

```text
grader.cpp
task.h
task.cpp
solutions/
statement/
tests/
scorer.txt
checker.cpp
```

For Communication, relevant source roles often include:

```text
manager.cpp
stub.cpp or stub.<lang>
public headers
contestant template/source
solutions/
tests/
statement/
metadata describing num_processes and task-type parameters
```

This is a role list, not an importer specification.

## Tests

- Preserve the repository's naming scheme by default.
- `001.in` / `001.out` is a useful cleaned-package convention when normalization is requested, but do not force it over a loader's required names.
- Communication tasks may not need ordinary `.out` answer files because the manager can directly produce an outcome.

## Non-Inference

- A sample grader is not necessarily the official CMS grader/manager.
- A contestant stub is not a model solution.
- A manager is not a checker.
- Communication task scoring may be emitted directly by the manager; do not invent answer files/checkers when they are not part of the protocol.
