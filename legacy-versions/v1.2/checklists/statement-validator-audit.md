# Statement Validator Audit Checklist

- Extract every input constraint from the statement, including semantic constraints such as nonempty lists.
- Compare statement constraints with the validator, grader/parser, and solution constants.
- Record every mismatch and choose the source of truth.
- Patch or supplement local validators when they miss statement constraints.
- Run an independent statement scan on generated tests before calling them valid.
- Recheck indexing, total-sum bounds, value/color ranges, and structural graph/string/grid constraints.
- Invalidate earlier benchmark logs if their inputs fail statement validation.
