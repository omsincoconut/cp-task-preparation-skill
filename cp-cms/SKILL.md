---
name: cp-cms
description: "Realize, validate, and package competitive-programming tasks for Contest Management System (CMS). Own CMS task-type/loader integration, statements, tests/scoring configuration, validators/checkers, graders/managers/stubs, and Communication protocols; use cp-test-case for substantial testcase semantics."
---

# CP CMS

Own the **CMS realization and package lifecycle**. CMS task semantics do not imply one universal authoring filesystem layout, so identify the target loader/repository convention before normalizing files.

## Ownership

This skill owns:

- CMS task-type and loader/repository discovery;
- concrete testcase IDs/files and score/subtask configuration;
- statements and package metadata;
- validators/checkers and grader/library integration;
- Communication managers, stubs, process configuration, hidden-input boundaries, and manager-output protocol;
- compile/integration verification possible outside a live CMS worker/importer.

For **why tests exist**, adversarial construction, wrong-solution separation, stress design, or benchmark tuning, use `cp-test-case` and consume its `cp-test-plan/v1` contract.

## Workflow

1. Identify the intended CMS version/task type and exact loader/repository convention.
2. Inspect roles with `checklists/package-inspection.md`.
3. For substantial testcase work, obtain/update a `cp-test-plan/v1` plan with `cp-test-case`.
4. Map the plan with `references/test-integration.md` and `templates/test-integration.md`.
5. Configure task-specific validators/checkers/graders/managers/stubs using `references/cms.md` and `references/validation.md`.
6. For Communication, load `references/communication.md`, use `examples/elevator/README.md` when useful, and run `checklists/communication-verification.md`.
7. Map scoring/subtasks with `references/scoring.md`; preserve the distinction between per-test outcomes and score aggregation.
8. Audit cross-file limits/protocol wiring with `references/package-consistency.md`.
9. Run `checklists/test-plan-integration.md` and `checklists/final-verification.md`.
10. State any behavior that cannot be verified without the actual CMS importer/worker instead of fabricating certainty.

## Communication Boundary

CMS `Communication` is distinct from `Interactive`. The admin-controlled manager owns hidden testcase input and communicates with one or more contestant processes; optional language stubs mediate that protocol. The manager ultimately reports the testcase outcome/message in the configured CMS protocol. Do not turn Communication into ordinary answer-file checking unless the target task actually requires that design.

## Package Layout Rule

Use, in order: user/contest convention, named importer/loader requirements, existing repository structure, then a cleaned internal layout only when explicitly useful. The bundled Elevator tree is an example of one contest workflow, not a canonical CMS filesystem format.

## Reference Map

- Test-plan interface: `contracts/test-plan-v1.md`
- CMS task roles: `references/cms.md`
- Communication: `references/communication.md`
- Loader/layout discipline: `references/package-conventions.md`
- Test mapping: `references/test-integration.md`
- Validators/checkers/graders/managers: `references/validation.md`
- CMS scoring integration: `references/scoring.md`
- Cross-file consistency: `references/package-consistency.md`
- Multi-process example: `examples/elevator/README.md`
