---
name: cp-task-preparation
description: End-to-end workflow for preparing, cleaning, validating, and documenting competitive-programming task packages. Use when Codex needs to inspect or normalize Polygon/CMS/OI-style packages, write statements or editorials, distinguish graders/checkers/validators/interactors/scorers, design tests and generators, analyze false solutions, stress solutions, generate expected outputs, or document missing/uncertain task-package components.
---

# CP Task Preparation

Use this skill to prepare a competitive-programming task package from raw materials through final verification. Work end to end, but keep each subsystem separate: platform conventions, statements/editorials, solutions, validation, scoring, generators, tests, stress, and uncertainty notes.

## Core Guardrails

- Learn package conventions from local convention examples, not from arbitrary Codeforces layouts.
- Treat Codeforces/Polygon packages as testcase-generation references only unless the user explicitly asks for Polygon package work.
- Do not hallucinate missing files, semantics, model solutions, graders, validators, checkers, interactors, generators, or scoring rules.
- Preserve source evidence and uncertainty. If a component cannot be safely inferred, ask or document the uncertainty.
- Prefer modular task-specific decisions over imitating an entire package shape.
- Keep Polygon and CMS materials separated when both exist.
- For CMS/library tasks, make the public statement and official solutions function-oriented: document the required signature, avoid stdin/stdout wording unless the task is explicitly batch, and keep graders/stubs separate from contestant implementations.
- Prefer LaTeX math notation in statements and editorials. Use code formatting for code identifiers and signatures, not mathematical variables.
- Design testcase generation from analyzed wrong solutions, and document both the wrong ideas and the tests that target them.
- When a wrong solution is identified, try to make it fail in as many applicable subtasks as the official constraints allow. Do not assume small subtasks should have weak tests.
- Prefer a small number of strong, concrete, multi-purpose tests over many narrow tests when the same wrong-solution coverage can be achieved.

## Workflow

1. Identify task type and platform: batch, library/sample-grader, output-only, interactive, communication, custom-scored; Polygon, CMS, mixed, or unknown.
2. Inspect package contents using `checklists/package-inspection.md`.
3. Normalize package conventions using `references/package-conventions.md`, then read `references/polygon.md` or `references/cms.md` as applicable.
4. Write or clean statement and editorial from `templates/statement.md` and `templates/editorial.md`; for natural subtask progressions, present subtasks/brute ideas before the final solution in the editorial.
5. Classify solutions: model, brute, subtask, partial, wrong, slow, contestant stub, or unknown. For library tasks, solution files should implement the required function without `main`.
6. Design validators, checkers/interactors, scorers, generators, and tests using the relevant references. Use split, intent-named generators, preserve subtask overlap in scorer summaries, and verify important solutions against each subtask.
7. Generate expected outputs only when there is a trusted solution/grader path.
8. Stress and verify with `checklists/final-verification.md`.
9. Document missing components, testcase intent, wrong-solution analysis, and uncertainty with `references/workflow-and-uncertainty.md`.

## Reference Map

- Package layout and naming: `references/package-conventions.md`
- Polygon packages: `references/polygon.md`
- CMS packages: `references/cms.md`
- Validators, checkers, interactors, graders, scorers: `references/validation-and-scoring.md`
- Testcase and generator design: `references/testcase-generation.md`
- Wrong/partial/slow solution analysis: `references/false-solution-analysis.md`
- Interactive and communication tasks: `references/interactive-and-communication.md`
- Uncertainty and workflow notes: `references/workflow-and-uncertainty.md`

## Reusable Files

- Templates: copy or adapt files from `templates/` for statements, editorials, notes, scorer summaries, generator scripts, and stress scripts.
- Checklists: use `checklists/skill-application.md` at the start, then apply focused checklists before final delivery.
- For new packages with generated tests, include `test_description.md` and, when wrong-solution analysis influenced tests, `wrong_solution.md` plus sources under `wrong/`.

## Test Naming Defaults

- Polygon tests: `01`, `01.a`, `02`, `02.a`, preserving existing Polygon IDs when already present.
- CMS tests: `001.in`, `001.out`, `002.in`, `002.out`.
- If legacy names encode subtasks, preserve the mapping in cleaning notes before normalizing.
