# Testcase Coverage Checklist

- Samples are included and match the statement.
- Minimum-size cases are covered.
- Maximum-size or near-limit cases are covered.
- Boundary values are covered.
- Duplicate/all-equal/single-different cases are covered when relevant.
- Structured cases are covered before random cases.
- Graph/tree/string/bitwise-specific edge cases are covered when relevant.
- Each subtask has representative tests.
- Each known wrong solution has at least one targeted case or documented reason why not.
- Each important wrong or partial solution has an explicit solution-by-subtask verdict expectation.
- Wrong solutions are tested against smaller subtasks when the official constraints allow the bug to appear there.
- The suite avoids unnecessary bloat when a smaller set of stronger tests gives the same coverage.
- Random generators have fixed seeds or reproducible commands.
- Stress testing compares trusted model and brute on small cases.
