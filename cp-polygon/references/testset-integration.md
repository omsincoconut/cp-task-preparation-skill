# Polygon Testset Integration

This file maps a platform-neutral Test Plan into Polygon semantics.

## Mapping

- Logical case IDs -> Polygon test numbers/commands.
- Logical groups/subtasks -> Polygon groups/testsets/dependencies/points as required by the target contest.
- Platform-neutral generator recipes -> concrete testlib/manual generator implementations.
- Oracle policy -> main solution / answer-generation path configured in Polygon.

Keep a mapping record when numbering is non-obvious or when an existing package's IDs must be preserved.

## Scoring and groups

Do not infer scoring merely because groups exist. Preserve existing group dependencies and point rules. If target-contest rules specify group structure, they override Codeforces defaults. Test-plan scoring describes semantic obligations; Polygon configuration owns concrete aggregation syntax.

## Verification

- Every planned logical case is implemented or explicitly deferred.
- No package test exists without a known role unless it is intentionally preserved legacy material.
- Every promoted generated input validates.
- Expected answers come only from the trusted full oracle path.
- Test numbering, group membership, dependencies, and generation commands agree with the final package state.
