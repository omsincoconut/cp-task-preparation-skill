# Statement Validation

Use this reference when deciding whether generated or preserved tests are valid under the problem statement.

## Source-Of-Truth Table

Before promoting tests, build a small table from all available sources:

| Constraint | Statement | Validator | Grader/parser | Solution constants | Decision |
|---|---|---|---|---|---|
| Example: `S_i >= 1` | yes | missing | accepts zero | assumes nonempty? | enforce statement |

- Prefer the statement for input validity unless the user confirms an official erratum.
- Use graders and public parsers to understand format and buffer limits, not to weaken statement constraints.
- Use solution constants as hints only; do not let them override the statement without evidence.

## Independent Statement Scan

For important generated tests, run two checks:

- The official or local validator.
- A task-specific scan for every statement constraint, especially semantic constraints that validators often miss.

Common missed checks:

- Lower bounds such as `S_i >= 1`, nonempty strings, or positive weights.
- Total-sum bounds across arrays or graph labels.
- Indexing convention: 0-indexed versus 1-indexed.
- Structural requirements such as connectedness, acyclicity, uniqueness, or sortedness.
- Color/value domains when samples and solution constants use different limits.

## Reporting

- Say "passes the local validator" only when that is all you know.
- Say "statement-valid" only after reconciling the statement and running an independent scan.
- If the validator is incomplete, either patch the local validator or document the missing checks before continuing.
- When a previously promoted test is invalid, invalidate its logs and regenerate the top cases under the real constraints.
