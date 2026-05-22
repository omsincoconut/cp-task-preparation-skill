# Regression And Benchmarking

Use this reference after updating the skill to test whether the update improves future task sessions without making retrieval noisier.

## Lightweight Regression Philosophy

- Test behavior, not prose volume.
- Prefer a few targeted scenarios over broad artificial coverage.
- Verify the update fixes the reviewed weakness and does not weaken old capabilities.
- Measure retrieval precision: the right files should be loaded, and unrelated methodology should stay unloaded.

## Progressive Scenarios

1. Smoke routing: simple package-cleaning scenario.
2. CMS/library scenario: grader, header, statement framing, and scorer behavior.
3. Testcase-generation scenario: wrong solutions, subtasks, mechanism-isolating tests, and statement validation.
4. Countertest/benchmark scenario: direct redirection, logs, conservative claim classification.
5. Mixed-platform scenario: Polygon/CMS/local separation and uncertainty reporting.

## Regression Checks

- Confirm all routes in `SKILL.md` point to existing files.
- Use `rg` for key concepts and verify canonical ownership.
- Re-run relevant checklists after updates.
- Confirm failure-mode additions are mechanism-oriented and indexed.
- Record results with `templates/regression-run.md`.
