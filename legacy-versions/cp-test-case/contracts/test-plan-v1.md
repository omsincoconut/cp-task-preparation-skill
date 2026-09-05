# Test Plan Contract v1

This file is the stable handoff interface between `cp-test-case` and a platform skill (`cp-polygon` or `cp-cms`). The contract is intentionally platform-neutral.

## Ownership

- `cp-test-case` **produces** the semantic test plan.
- `cp-polygon` / `cp-cms` **consume** it and map logical cases/groups to platform files, IDs, scripts, and configuration.
- Platform skills may append integration metadata, but must not silently change the semantic intent of a case or group.

## Required fields

A handoff should contain these sections, in Markdown, YAML, or equivalent structured form:

1. **Contract version**: `cp-test-plan/v1`.
2. **Task model**: batch, library, output-only, interactive, communication, or custom-scored; include only semantics relevant to tests.
3. **Validity basis**: statement constraints, semantic constraints, and any confirmed validator/manager restrictions that affect legal inputs.
4. **Oracle basis**: trusted full solution/grader/manager path; identify any small brute oracle separately.
5. **Logical groups/subtasks**: stable logical IDs, promises/constraints, points or dependency semantics when relevant to test design.
6. **Case families**: stable logical case IDs or families, purpose, scale, construction recipe, and deterministic replay requirements.
7. **Targets**: wrong/partial/slow behavior each adversarial family is intended to separate; include expected verdicts where evidence exists.
8. **Expected-output policy**: whether ordinary answer files exist and which trusted path may generate them.
9. **Evidence**: validation, stress, benchmark, or exhaustive-check results supporting promoted cases.
10. **Residual risk**: untested behavior, missing oracles, uncertain constraints, or platform-dependent assumptions.

## Logical IDs

Logical IDs are semantic names such as `tiny-exhaustive`, `overflow-boundary-1`, or `sub2-chain-max`. They are **not** Polygon test numbers or CMS dataset filenames. The platform skill owns that mapping.

## Generator boundary

The plan specifies *what to generate* and the reproducibility requirements, not a platform API. For example:

- good: “uniform random tree, `n=200000`, seed recorded, bias toward long diameter”;
- not part of this contract: `rnd.next`, Polygon Freemarker commands, CMS importer filenames, or a particular RNG library.

## Change rule

If platform constraints make a planned case impossible to realize, the platform skill must report the mismatch and either:

- preserve intent with an equivalent legal implementation, or
- return the issue to testcase design for a semantic plan change.

Do not silently weaken adversarial intent merely to fit a package convention.
