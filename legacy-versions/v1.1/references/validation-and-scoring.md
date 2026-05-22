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

Use `templates/scorer.txt` as a starting point. Include:

- Subtask point values.
- Test groups or regex patterns.
- Dependencies between subtasks when relevant.
- Notes when real scoring depends on `scorer.cpp` or grader protocol output.
- Preserve overlap: when a testcase satisfies multiple subtasks, include it in every applicable group.
- Do not force tests into disjoint groups unless the platform requires disjoint scoring and that requirement is documented.

## Expected Outputs

Generate outputs only when a trusted oracle exists:

- Full model solution for batch tasks.
- Trusted grader plus model for library tasks.
- Official answer files.

Do not use partial, subtask, or unknown solutions to generate full outputs.
