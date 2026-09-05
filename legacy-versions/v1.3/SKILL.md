---
name: cp-task-preparation
description: End-to-end workflow for preparing, cleaning, validating, and documenting competitive-programming task packages. Use when Codex needs to inspect or normalize Polygon/CMS/OI-style packages, write statements or editorials, distinguish graders/checkers/validators/interactors/scorers, design tests and generators, analyze false solutions, stress solutions, generate expected outputs, document missing/uncertain task-package components, or refine this skill from active-session or post-session findings.
---

# CP Task Preparation

Use this skill to prepare competitive-programming task packages end to end. Keep each subsystem separate: package conventions, statements/editorials, solution roles, validation, scoring, generators, tests, stress, benchmarks, and uncertainty notes.

## Core Guardrails

- Learn package conventions from local convention examples, not arbitrary Codeforces layouts.
- Treat Codeforces/Polygon packages as testcase-generation references only unless the user explicitly asks for Polygon package work.
- Do not hallucinate missing files, semantics, model solutions, graders, validators, checkers, interactors, generators, or scoring rules.
- Preserve source evidence and uncertainty. If a component cannot be safely inferred, ask or document the uncertainty.
- Keep Polygon, CMS, and local-grader materials separated when more than one exists.
- Reconcile statement constraints against validators, graders, parsers, and solution constants before calling generated tests valid.
- Generate expected outputs only from a trusted oracle path.
- Load focused references only when their subsystem is relevant; do not load the whole skill library by default.
- Keep methodology canonical: update one owner file and route to it instead of duplicating guidance.

## Folder Organization

- `polygon/`: Polygon package materials.
- `cms/`: CMS package materials.
- `local/`: local grader package. See `references/local-grader.md` for required files and `mass_grader.cpp` output.
- `markdowns/`: statements, editorials, summaries, testcase notes, run results, verification notes, and wrong-solution notes.
- `tmp/`: files irrelevant to the folders above.

Full target-layout rules live in `references/package-conventions.md`.

## Workflow

1. Identify task type and platform: batch, library/sample-grader, output-only, interactive, communication, custom-scored; Polygon, CMS, local, mixed, or unknown.
2. Inspect package contents using `checklists/package-inspection.md`.
3. Normalize package layout and naming using `references/package-conventions.md`; add `references/polygon.md`, `references/cms.md`, or `references/local-grader.md` only when applicable.
4. Write or clean statement/editorial from `templates/statement.md`, `templates/editorial.md`, and `references/writing.md`; for CMS/library tasks, load `references/cms.md`.
5. Classify solutions using `references/solution-analysis.md`.
6. Audit statement constraints with `references/statement-validation.md` and `checklists/statement-validator-audit.md` before promoting tests or outputs.
7. For validators, checkers, interactors, graders, and protocols, use `references/validation.md`; for subtasks, `scorer.txt`, `scorer.cpp`, and custom scoring, use `references/scoring.md`.
8. For generators and testcase suites, use `references/testcase-generation.md`; after identifying a task family or wrong assumption, route through `failure-modes/INDEX.md` and load only relevant topic files.
9. For counterexamples, use `references/countertest-methodology.md` and `checklists/countertest-promotion.md`.
10. For runtime or memory claims, use `references/benchmarking.md` and `checklists/benchmark-harness.md`.
11. Stress and verify with `checklists/final-verification.md`.
12. Document missing components, residual risk, and confidence using `references/epistemics-and-uncertainty.md`.
13. When the user asks to improve the skill during or after a task session, use `references/refinement-workflow.md`.

## Reference Map

- Package layout, folder organization, file roles, test naming: `references/package-conventions.md`
- Polygon packages: `references/polygon.md`
- CMS/library packages: `references/cms.md`
- Local grader package: `references/local-grader.md`
- Validators, checkers, interactors, graders: `references/validation.md`
- Scoring, subtasks, `scorer.txt`, `scorer.cpp`: `references/scoring.md`
- Statement constraint audits: `references/statement-validation.md`
- Statement/editorial writing style: `references/writing.md`
- Solution role and wrong-solution analysis: `references/solution-analysis.md`
- Testcase and generator design: `references/testcase-generation.md`
- Failure-mode library for testcase generation: `failure-modes/INDEX.md`
- Countertests and claim promotion: `references/countertest-methodology.md`
- Benchmarking and TL/ML reporting: `references/benchmarking.md`
- Interactive and communication tasks: `references/interactive-and-communication.md`
- Uncertainty and evidence discipline: `references/epistemics-and-uncertainty.md`
- Skill refinement: `references/refinement-workflow.md`

## Reusable Files

- Templates: copy or adapt files from `templates/` only after confirming the component is needed. Put shared markdown deliverables under `markdowns/` and scratch artifacts under `tmp/`; clean obsolete `tmp/` outputs before final delivery.
- Checklists: use `checklists/skill-application.md` at the start, then apply focused checklists before final delivery.
- For new packages with generated tests, include `markdowns/test_description.md`, `markdowns/run_results.md`, and, when wrong-solution analysis influenced tests, `markdowns/wrong_solution.md` plus sources under `wrong/`.
