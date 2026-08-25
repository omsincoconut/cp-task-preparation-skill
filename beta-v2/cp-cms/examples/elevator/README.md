# Elevator Communication Example

This is a reduced source-only reference extracted from the user-supplied `elevator` package (EJOI 2026 Day 2). It is included to demonstrate roles in a multi-process CMS Communication task; it is **not** a universal CMS package template.

Included:

```text
task_info.yaml
system/
  manager.cpp
  stub.cpp
  elevator.h
  constraints.h
contestant/
  grader.cpp
  stub.cpp
  elevator.h
  elevator.cpp
  constraints.h
  compile_cpp.sh
  run_cpp.sh
  sample.01.in
```

## Role Map

- `system/manager.cpp`: deployed/admin-side protocol and scoring logic. Reads hidden input and communicates with many contestant processes.
- `system/stub.cpp`: contestant-process entry point. Receives a process index and maps communication to `press_buttons` / `answer` calls.
- `system/elevator.h`: contestant API declaration used by the system stub.
- `contestant/grader.cpp`: local simulator for contestant testing. It does not reproduce CMS sandbox/FIFO separation exactly and must not be mistaken for the official manager.
- `contestant/elevator.cpp`: blank contestant implementation template.
- `task_info.yaml`: contest-repository metadata from this example; it is not asserted to be CMS's universal import schema.

The original statements, presentation PDFs, model solutions, and large official tests are intentionally omitted because they are unnecessary for teaching the Communication package roles.
