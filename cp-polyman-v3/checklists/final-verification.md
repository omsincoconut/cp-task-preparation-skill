# Polygon Final Verification Checklist

- Target-contest/user rules are explicit; they override bundled Codeforces defaults.
- All configured sources exist and compile with intended settings.
- All randomness in Polygon generators comes from `testlib.h` unless an explicit override is documented.
- Every promoted input passes the intended validator.
- Test Plan logical cases/groups are mapped completely or unresolved gaps are reported.
- Generation commands, test numbering, groups/dependencies/points, and materialized tests agree.
- Trusted main/oracle path is identified before answer generation.
- Checker/interactor behavior matches the statement and does not leak hidden data.
- Statement limits match validator and package metadata.
- Required statement languages and samples are present.
- If Polyman is used, local verification succeeds or failures are reported precisely.
- No API keys, secrets, credentials, binaries, or irrelevant scratch files are packaged unintentionally.
