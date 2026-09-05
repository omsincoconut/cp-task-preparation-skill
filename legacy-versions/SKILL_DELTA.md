# CP Task Preparation Skill Delta

## Purpose

Use this file as a corrective overlay after loading the main `cp-task-preparation` skill. It is not a replacement workflow, methodology rewrite, or duplicate skill. Its job is to patch recurring current-model failures observed in package-preparation sessions.

Prefer routing to existing canonical owners over restating their full guidance. If a mistake is caused by retrieval, checklist, template, or enforcement drift, load and apply the existing reference/checklist instead of inventing local policy.

## Retrieval Triggers

- If the statement has subtasks, official scores, or subtask promises, load `references/scoring.md` before planning package deliverables. Explicitly decide whether `cms/scorer.txt` is required and how test membership maps to subtasks.
- If Polygon tests, validators, generators, or `gen_script.txt` are involved, load `references/polygon.md` and `references/testcase-generation.md` before implementing them.
- If the brief names wrong, partial, slow, or fragile solution families, load `references/solution-analysis.md` and treat those families as evidence targets, not optional inspiration.
- If runtime limits, asymptotic separation, TLE risk, or slow variants matter, load `references/benchmarking.md` and `checklists/benchmark-harness.md`.
- Before final delivery, load `checklists/final-verification.md` and use it as an artifact/evidence audit, not as a passive read.

## Execution Drift Checks

- Do not omit `cms/scorer.txt` from planning when subtasks and scores exist. This was missed early in `sort_array` even though the scoring guidance already existed.
- Treat `gen_script.txt` as a structured Polygon deliverable. Follow the conventions in `references/polygon.md`; do not leave an ad hoc or non-Freemarker-style script when the package expects Polygon generation.
- Avoid monolithic mode-dispatch generators for unrelated testcase mechanisms. Descriptive parameters are fine inside one mechanism, but random, reverse, duplicate-trap, alternating, block, and shuffle families should usually be separate generator sources.
- Probe environment-sensitive dependencies early. If the package assumes `testlib.h`, scripts, compiler behavior, or shell redirection, validate a tiny compile/run path before building the whole package around that assumption.
- Treat generator/script/test synchronization as IO-critical. Check that materialized files preserve intended lines, encoding, and endings; Windows PowerShell capture/piping can corrupt multiline generator output or strict validator input.

## Testcase And Benchmark Discipline

- Prefer generator-derived promoted tests end to end, including tiny/manual cases where practical. "Manual" should usually mean manually parameterized generator output, not unsynchronized handwritten files.
- If the task brief names wrong-solution families, implement representative variants or explicitly justify omissions in the verification notes. `is_permutation` under-covered its hinted wrong families by implementing only the range-only checker.
- Full-subtask tests must have real large-limit diversity. Do not rely on lower-subtask-style cases plus one max-size token test; include distinct high-N mechanisms that target the strongest legal failures.
- Make random and random-max decisions explicit. They are not mandatory decoration, but the package should record whether they add coverage and why they were included or omitted.
- Benchmark evidence should prove more than "the model passes quickly." Where runtime matters, measure or reason from concrete slow/borderline candidates and record what the suite separates.

## Package Hygiene

- Preserve canonical ownership: contestant stubs expose the interface, graders own executable IO, official solutions implement the library function, and verification helpers stay outside contestant-owned files.
- For CMS/local library tasks, official solution files should not contain `main`; link them with the grader harness instead. This drift occurred during `is_permutation` and had to be repaired.
- Prefer local include style such as `#include "task.h"` with explicit include paths over parent-directory climbing such as `#include "../task.h"` where practical.
- Keep one constraints owner where possible, then audit mirrored metadata, scorer membership, tests, docs, and verification notes after any change. Synchronization includes semantic artifacts, not only numeric constants.
- Do not print fake-precise metrics. If memory is unmeasured, do not report `0.00 MB` as though it were evidence; document the metric as unavailable, approximate, or intentionally omitted.

## Verification Evidence

- `run_results.md` should make the solution-by-subtask story visible: important solution class, intended verdict, observed verdict, failing tests/subtasks, timing evidence, and unresolved risk.
- Wrong-solution documentation must be empirically checked against promoted tests. In `is_permutation`, a duplicate-trap case initially failed to trap the documented wrong solution; that mismatch had to be found by comparing actual outputs.
- Validator/generator verification must include materialized official tests, not only generator commands. A valid script call is insufficient if shell serialization produced malformed files.
- Review markdown formatting during final audit. Use LaTeX-style math for constraints, sets, inequalities, and asymptotics; reserve code formatting for code symbols, filenames, commands, and literal syntax.
- Record deviations plainly. If preferred guidance cannot be followed because of local toolchain limits, explain the probe, fallback, and residual risk instead of silently normalizing the workaround.

## Session Examples

- `sort_array`: initial planning missed `cms/scorer.txt`; `gen_script.txt` did not follow the intended Polygon/Freemarker convention; one mode-dispatch generator owned unrelated mechanisms; local memory reporting printed `0.00`; slow-solution/TLE benchmarking stayed too shallow.
- `is_permutation`: `testlib.h` incompatibility was discovered late; PowerShell multiline handling corrupted generated tests; only one of several hinted wrong-solution families was implemented; full-subtask stress diversity was narrow; CMS official solutions initially contained `main`.

