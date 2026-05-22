# Validation And Scoring

Use this reference when designing or classifying validators, checkers, interactors, graders, and scorers.

## Distinctions

- Validator: checks input format and constraints.
- Checker: checks contestant output against the official answer or validity rules.
- Interactor: communicates with an interactive contestant during execution.
- Grader: calls contestant code for library or communication tasks.
- Scorer: converts verdicts, groups, or custom protocol outputs into points.

## Validator Design

- Encode every statement constraint that affects valid input.
- Audit validators against the statement before relying on them for generated-test validity; sample graders may accept inputs the statement forbids.
- Add structural checks for graphs, trees, permutations, strings, grids, and query limits.
- Test invalid cases separately if the platform supports validator tests.
- Avoid over-restricting based on generator habits.

## Checker Design

- Use standard exact-output checking when output is uniquely determined and formatting is simple.
- Use a custom checker for constructive output, multiple valid answers, floating/numeric tolerance, graph objects, or proof certificates.
- A checker is not the same as custom scoring.
- For yes/no tasks, ensure the checker handles case, whitespace, and impossible-instance claims correctly.

## Interactor Design

- Define query format, response format, limits, termination, and invalid-query behavior.
- Decide whether the interactor is adaptive or non-adaptive.
- Ensure samples and local testing scripts reflect the interaction protocol.

## Scorer Files

For CMS packages, `scorer.txt` is the system write-up of which tests belong to
which subtasks. Use the exact array format from `templates/scorer.txt`:

```text
[
  [POINTS, "(TEST_PATTERN)"]
]
```

- Use CMS-style test ids such as `001`, `002`, not prose group names.
- Preserve overlap: when a testcase satisfies multiple subtasks, include it in every applicable subtask pattern.
- Do not add explanatory prose, comments, limits, dependencies, or protocol notes to CMS `scorer.txt`.
- Document scoring caveats, `scorer.cpp`, checker behavior, grader protocol behavior, or uncertainty in package notes instead.
- Do not force tests into disjoint groups unless the platform requires disjoint scoring and that requirement is documented outside `scorer.txt`.

## Expected Outputs

Generate outputs only when a trusted oracle exists:

- Full model solution for batch tasks.
- Trusted grader plus model for library tasks.
- Official answer files.

Do not use partial, subtask, or unknown solutions to generate full outputs.
