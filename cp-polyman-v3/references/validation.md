# Polygon Validation Components

## Roles

- Validator: reads problem input and accepts only inputs satisfying format and constraints.
- Checker: reads contestant output and official answer/context and determines correctness or score according to output rules.
- Interactor: communicates with an interactive submission during execution.
- Generator: creates test input; it does not prove that input is valid.

## Validator Design

- Encode every statement constraint that affects validity.
- Use the same variable terminology as the statement when required by the target contest.
- Check global/sum constraints, structural properties, and end-of-file expectations deliberately.
- Do not over-restrict based only on what generators happen to produce.
- Run the validator against every promoted/generated test.

## Checker Design

- Prefer a standard checker when it exactly matches the output contract.
- Use a custom checker for multiple valid outputs, constructive certificates, tolerances, or semantic validation.
- Bound reads from contestant output and answer streams.
- Avoid leaking hidden information through contestant-facing messages.

## Interactor Design

- Specify query/response/final-answer protocol, query limits, termination, invalid action behavior, and flushing requirements.
- Decide whether hidden behavior is adaptive or fixed.
- Verify the local interaction harness matches the deployed protocol.

## testlib

Use `references/testlib.h` as the bundled default version unless the package pins another version or the user requests an update. For API usage, inspect the header and official testlib documentation rather than guessing function signatures.
