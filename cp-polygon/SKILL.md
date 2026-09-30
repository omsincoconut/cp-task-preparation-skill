---
name: cp-polygon
description: "Realize, validate, and package competitive-programming problems for Codeforces Polygon or Polygon-compatible workflows. Own Polygon metadata, statements, validators/checkers/interactors, testlib-based generators, tests/groups, generation wiring, package verification, and Polyman operations; use cp-test-case for substantial testcase semantics."
---

# CP Polygon

Own the **Polygon realization and package lifecycle**. Do not duplicate deep testcase-design methodology.

## Authority Order

1. Explicit user instructions and target-contest rules.
2. Existing package conventions when preserving/repairing a package.
3. `references/codeforces_polygon_rules.md` as the default policy when no other contest rules are supplied.
4. Polygon/Polyman references in this skill.

The bundled Codeforces rules are defaults, not universal Polygon requirements.

## Non-Negotiable Default for Randomness

Unless the user or target-contest rules explicitly state otherwise, **all randomness in Polygon generators must be sourced from `testlib.h`**. Do not use `rand()`, `<random>`, custom RNGs, time-based seeding, or another random source. See `references/generators.md`.

## Ownership

This skill owns:

- Polygon/Polyman package discovery and normalization;
- problem metadata, statement files/languages, and package-level consistency;
- validators, checkers, interactors, and their compilation/integration;
- concrete generators and generation commands;
- Polygon test numbers, groups/testsets, dependencies, points, and answer generation wiring;
- Polyman pull/verify/commit/push/package workflows when requested.

For **why tests exist**, adversarial construction, wrong-solution separation, stress design, or benchmark tuning, use `cp-test-case`. Consume its `cp-test-plan/v1` contract.

## Bundled Defaults

- `references/codeforces_polygon_rules.md`: supplied Codeforces defaults; user/contest rules override them.
- `references/defs.toml`: supplied statement snippets/macros.
- `references/testlib.h`: supplied default testlib header.
- `references/polyman.md`: Polyman CLI guidance.

Do not silently replace a package-pinned `testlib.h` version.

## Workflow

1. Identify native Polygon vs Polyman and the target contest/rule authority.
2. **If using Polyman**, check version with `polyman --version`:
   - **V3 (3.0.0+)**: Consider using `cp-polyman-v3` skill (built for AI agents with JSON output, compile cache, workspace docs)
   - **V2 or legacy**: Continue with this skill
   - **Migrating V2→V3**: See `v3_migration.md` for generator script conversion (JSON arrays → Freemarker text files)
3. Inspect roles with `checklists/package-inspection.md`.
4. Load Codeforces defaults only when no higher-priority contest rules exist.
5. If testcase design is substantial, obtain/update a `cp-test-plan/v1` plan with `cp-test-case`.
6. Map that plan using `references/testset-integration.md` and `templates/test-integration.md`.
7. Implement generators with `references/generators.md`; enforce testlib-only randomness by default.
8. Implement/audit validators, checkers, and interactors with `references/validation.md`.
9. Audit cross-file limits and wiring with `references/package-consistency.md`.
10. For Polyman workspaces, use `references/polyman.md` and verify version-sensitive CLI flags with installed `--help` before mutating operations. On Windows, run `scripts/probe-polyman-io.ps1` against one known generated test before running a full verify or a remote push.
11. Run `checklists/test-plan-integration.md` and `checklists/final-verification.md` before delivery or remote operations.

## Remote Operations

Never print or package Polygon API secrets. Treat Polyman remote commit/push/package operations as mutating; run them only when explicitly requested and credentials are securely configured. Prefer local verification first.

## Reference Map

- **Polyman V3 migration**: `v3_migration.md` — V2→V3 generator script conversion
- Test-plan interface: `contracts/test-plan-v1.md`
- Polygon roles/layout: `references/polygon.md`, `references/package-conventions.md`
- Generator implementation/randomness: `references/generators.md`
- Test/group mapping: `references/testset-integration.md`
- Validators/checkers/interactors: `references/validation.md`
- Cross-file consistency: `references/package-consistency.md`
- Polyman: `references/polyman.md`
- Codeforces defaults: `references/codeforces_polygon_rules.md`
- Statement definitions/macros: `references/defs.toml`
- Bundled testlib: `references/testlib.h`
