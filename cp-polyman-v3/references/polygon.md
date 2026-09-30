# Polygon Reference

Use for native Polygon package work and Polygon-bound repositories.

## Inspect First

1. Determine whether the source is a Polygon export/package, a hand-maintained source repository, or a Polyman workspace.
2. Locate problem metadata, statements, solutions, validator, checker/interactor, generators, testset scripts, and test files.
3. Identify the trusted main solution before generating answers.
4. Reconcile statement constraints with validators and generator bounds.
5. Preserve solution tags/status evidence where present.

## Test Generation Wiring

- Keep generator command intent explicit and reproducible.
- For testlib-based generators use `#include "testlib.h"` and compile with an include path rather than fragile parent-directory includes.
- Preserve deterministic seeds/arguments when a test must be reproducible.
- Use the package's actual Polygon testset/generation-script representation; do not invent Freemarker syntax if the source uses another supported/exported representation.
- If the target is Codeforces and no override is supplied, consult `codeforces_polygon_rules.md` for current provided defaults such as generator/test policy.

## Statements

- Preserve all requested languages.
- Apply `defs.toml` only when those definitions/macros are supported by the target statement environment.
- For Codeforces work, treat `codeforces_polygon_rules.md` as the bundled default; for other contests, user/contest style wins.

## Auxiliary Programs

- Use `testlib.h` for validators/checkers/generators/interactors when required by the target workflow.
- Keep validator, checker, and interactor responsibilities separate.
- Do not validate the input inside a checker just because the data is available there.

## Package Verification

Before delivery or push:

- all referenced sources exist and compile;
- generated inputs pass the validator;
- the main solution produces answers successfully;
- checker/interactor behavior matches the statement;
- generation commands and test ordering match the intended suite;
- statement limits match executable enforcement;
- no API credentials or local-only secrets are included.
