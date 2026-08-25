# CMS Test Plan Integration Checklist

- Test Plan contract is `cp-test-plan/v1` or equivalent fields are recoverable.
- Target CMS task type and exact loader/repository convention are identified.
- Every logical case/group maps to concrete testcase/scoring configuration or an explicit unresolved note.
- Replay/generation requirements survive the mapping.
- Every test satisfies the intended validity restrictions.
- Expected-output handling matches task type: answer files only when required; manager-driven outcomes for Communication when appropriate.
- Scoring/group mapping preserves semantic intent and overlap/dependencies.
