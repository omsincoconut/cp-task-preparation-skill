# Polygon Package Inspection Checklist

- Identify native Polygon export/repository vs Polyman workspace vs mixed repository.
- Identify target contest and explicit rule overrides before applying Codeforces defaults.
- Locate problem metadata, statements/languages, validators, checker/interactor, generators, solutions, tests/testsets/groups, and generation scripts.
- Identify the intended `testlib.h` version and whether the package pins its own copy.
- Identify the trusted main solution from metadata/evidence; do not prove it correct here.
- Record existing test numbers/group semantics before changing them.
- If testcase semantics need substantial redesign, hand off to `cp-test-case` rather than recreating that methodology here.
