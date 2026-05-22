# Final Verification Checklist

- Package layout matches the intended platform separation.
- Statement and editorial are present and do not contain unverified claims.
- Validators compile or are clearly documented as unverified.
- Statement constraints have been reconciled against validators and generated tests.
- Checkers/interactors compile or are clearly documented as unverified.
- Model/brute/stress commands are run when available.
- Expected outputs are generated only by a trusted oracle.
- Scorer summary matches test naming and point groups, including overlapping subtask membership where valid.
- Custom scoring behavior is documented when code implements more than scorer text.
- Test renaming map is present if tests were renamed.
- `test_description.md` documents testcase intent, subtask membership, generator source, and targeted wrong solutions.
- `wrong_solution.md` and `wrong/` sources are present when wrong-solution analysis shaped tests.
- Important accepted, brute, partial, and wrong solutions have verified solution-by-subtask behavior, or documented reasons why a behavior cannot be tested under the subtask constraints.
- Countertests and performance claims include direct-redirection logs or are explicitly labeled as unverified/local artifacts.
- The final testcase count is justified by coverage; remove narrow tests when a stronger combined testcase covers the same purpose.
- Library-task statements and solutions avoid accidental stdin/stdout framing and unnecessary `main` functions.
- Missing components and residual risks are listed.
