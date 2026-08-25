---
name: cp-test-case
description: "Design and validate platform-independent competitive-programming testcase suites: coverage models, adversarial cases, generator specifications, countertests, oracle checks, regression/stress testing, and performance benchmarks. Use with cp-polygon or cp-cms when the suite must be integrated into a package."
---

# CP Test Case

Own the **semantics of the testcase suite**. Do not own Polygon or CMS file layout, RNG APIs, generation-script syntax, test numbering, checker/manager implementation, or package metadata.

## Responsibility

This skill answers:

- What legal behaviors and boundaries must the suite cover?
- Which wrong/partial/slow implementations should each adversarial family separate?
- What generator families and parameters are needed, independent of platform?
- Which oracle path makes expected results trustworthy?
- What stress/benchmark evidence supports coverage and TL/ML claims?

It produces a `cp-test-plan/v1` handoff defined in `contracts/test-plan-v1.md`.

## Non-Responsibilities

Leave these to the platform skill:

- Polygon `testlib.h`, Freemarker/generation commands, tests/groups, `problem.xml`, Polyman;
- CMS loader/import filenames, task configuration, graders/managers/stubs, scorer configuration;
- platform-specific compilation or package publishing.

The only platform facts retained here are semantic facts needed to shape tests, such as “this Communication task hides part of the input” or “this subtask has a promise.”

## Workflow

1. Extract the validity model, subtasks/groups, task semantics, and oracle candidates.
2. Reconcile legal-input constraints with `references/test-validity.md` and `checklists/test-validity.md`.
3. Classify supplied model/brute/wrong/partial/slow solutions with `references/solution-analysis.md` only to derive testcase obligations.
4. Design coverage and generator families with `references/testcase-generation.md`; load only relevant entries from `failure-modes/INDEX.md`.
5. For specific false claims, use `references/countertest-methodology.md` and `checklists/countertest-promotion.md`.
6. Build tiny exhaustive or hand-checkable oracle checks before scaling.
7. Add boundary, structured, adversarial, paired-control, randomized, and max-stress families only when each adds distinct coverage.
8. Benchmark slow/borderline implementations with `references/benchmarking.md` and `checklists/benchmark-harness.md`.
9. Run `checklists/testcase-coverage.md` and `checklists/final-verification.md`.
10. Emit or update a `cp-test-plan/v1` handoff; `templates/test-plan.yaml` is the preferred structured starting point.

## Handoff Rule

Logical case/group IDs remain stable across platforms. The platform skill maps them to concrete test IDs and files. If platform restrictions force a semantic change, do not silently alter the plan: report the mismatch and revise the plan deliberately.

## Reference Map

- Handoff interface: `contracts/test-plan-v1.md`
- Test design: `references/testcase-generation.md`
- Test validity: `references/test-validity.md`
- Failure-mode library: `failure-modes/INDEX.md`
- Solution behavior for testcase targeting: `references/solution-analysis.md`
- Countertests: `references/countertest-methodology.md`
- Benchmarking: `references/benchmarking.md`
- Regression: `references/regression-and-benchmarking.md`
- Platform-neutral scoring/subtask semantics: `references/scoring.md`
