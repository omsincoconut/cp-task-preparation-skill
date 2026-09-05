# Interactive And Communication

Use this reference for interactive, run-twice, communication, or grader-mediated tasks.

## Identification

Evidence includes:

- `interactor.cpp`, interaction scripts, or checker/interactor references.
- Statement language about queries, responses, hidden data, or runs.
- Grader files that call contestant functions rather than reading normal output.
- Samples showing transcripts or multiple runs.

## Interactive Tasks

- Define query syntax, answer syntax, final output syntax, and flush requirements.
- Enforce query limits in the interactor.
- Decide adaptive versus non-adaptive behavior.
- Include invalid-query handling and verdict behavior.
- Test hidden extremes and query-limit boundaries.

## Communication Or Run-Twice Tasks

- Separate first-run output, persistent state, second-run input, and final answer.
- Preserve graders and headers as interface definitions.
- Check that local testing scripts run both phases consistently.
- Do not assume CMS/OI communication conventions from Polygon examples alone.

## Validation And Testing

- Validator checks hidden data constraints, not contestant transcript validity.
- Interactor/grader enforces transcript or communication protocol.
- Checker may be present to wrap the interactor or final verdict.
- Stress using simulated hidden instances and known strategies when possible.
