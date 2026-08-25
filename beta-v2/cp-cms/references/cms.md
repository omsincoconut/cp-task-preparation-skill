# CMS Reference

CMS task type controls compilation/evaluation behavior. Determine the task type and loader/configuration rather than inferring it solely from files.

## Batch and Grader-Based Tasks

- Batch can compile the contestant source alone or with an admin-provided grader depending on task configuration.
- A grader usually handles I/O and calls contestant-implemented functions.
- Public headers define contestant interfaces; contestant templates/stubs are not official hidden solutions.
- A custom checker is used only when the output-comparison contract requires it.
- Generate answer files only from an official/trusted oracle path.

## Communication

Use `references/communication.md`. Communication is appropriate when some testcase input must remain hidden from contestant code during evaluation.

## Scoring

CMS task type outcomes and score types are distinct. A manager/checker may produce a per-test outcome that the configured score type later aggregates. Preserve this distinction when documenting subtasks and partial credit.

## Filesystem Formats

CMS can import from filesystem formats/loaders; repository structure is not itself the task type. If a target loader is named, follow its documentation exactly. The CMS Italian format and Polygon importer have specific conventions; custom loaders are also possible.

## Uncertainty

If manager binaries, task-type parameters, loader metadata, or a full model solution are missing, state what cannot be verified instead of fabricating it.
