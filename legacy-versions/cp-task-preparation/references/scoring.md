# Scoring

Use this reference for subtasks, `scorer.txt`, `scorer.cpp`, grouped scoring, custom scoring, and expected-output trust rules.

## Scorer Roles

- `scorer.txt`: system write-up of point values and testcase membership.
- `scorer.cpp`: executable or protocol-aware scoring behavior when present.
- Checker or grader protocol: may affect per-test score, fractional credit, or verdict mapping.

Do not infer custom scoring from the presence of a checker alone.

## CMS `scorer.txt`

For CMS packages, use the exact array format from `templates/scorer.txt`:

```text
[
[POINTS, "001|002|003"]
]
```

- Use CMS-style test ids such as `001`, `002`, not prose group names.
- Preserve overlap: when a testcase satisfies multiple subtasks, include it in every applicable subtask string.
- Separate test ids with literal `|`; do not use regex syntax, parentheses, comments, prose, limits, dependencies, or protocol notes in CMS `scorer.txt`.
- Document scoring caveats, `scorer.cpp`, checker behavior, grader protocol behavior, or uncertainty in package notes instead.
- Do not force tests into disjoint groups unless the platform requires disjoint scoring and that requirement is documented outside `scorer.txt`.

## Custom Scoring

- Confirm whether scoring is exact, grouped, partial, fractional, or protocol-driven.
- If `scorer.cpp` maps grader exit values or protocol tokens to fractions, document that behavior explicitly.
- Do not flatten partial scoring into regex groups if that would lose behavior.
- Keep point totals and dependency semantics auditable.

## Expected Outputs

Generate outputs only when a trusted oracle exists:

- Full model solution for batch tasks.
- Trusted grader plus model for library tasks.
- Official answer files.

Do not use partial, subtask, or unknown solutions to generate full outputs.
