# Validation

Use this reference when designing or classifying validators, checkers, interactors, graders, and protocol enforcement.

## Distinctions

- Validator: checks input format and constraints.
- Checker: checks contestant output against the official answer or validity rules.
- Interactor: communicates with an interactive contestant during execution.
- Grader: calls contestant code for library or communication tasks.

Use `references/scoring.md` for points, subtasks, `scorer.txt`, and custom scoring.

## Validator Design

- Encode every statement constraint that affects valid input.
- Source global limits and subtask thresholds from the package's canonical constraints owner where practical.
- Audit validators against the statement before relying on them for generated-test validity.
- After changing constraints, audit validators, generators, statements, scorers, local graders, and benchmark docs for stale copied limits.
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

## Grader Design

- Keep contestant-facing headers minimal and stable.
- Keep graders/stubs separate from contestant implementations.
- For library tasks, compile trusted solutions with the grader path before using them for output generation.
