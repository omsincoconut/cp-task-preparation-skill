# Polygon Package Conventions

Use this reference only for Polygon-oriented work.

## Deliverable Shape

When the user asks for a Polygon package itself, keep the deliverable Polygon-native: do not wrap it in a `polygon/` directory merely because a larger cleaning workspace once used that convention. When working inside a mixed repository, a `polygon/` staging directory is acceptable if it keeps platforms separated.

Typical source roles include:

```text
problem.xml or equivalent exported metadata
testlib.h
validator.cpp / validators/
checker.cpp / checker sources
interactor.cpp / interactors/
generators/
solutions/
statements/
scripts or generation script material
tests/ or materialized package tests
```

Actual exports and repositories differ. Preserve the package's real structure unless normalization is requested.

## Constraints

Prefer one canonical constraints owner where practical, then audit copied values in statements, validators, generators, solutions, scripts, and metadata. Do not invent a `constraints.h` if the project has a different established source of truth.

## Tests

- Preserve existing Polygon test IDs unless renaming is requested.
- For newly normalized local material, `01`, `02`, ... and paired answers such as `01.a` are acceptable defaults, but do not force this over a contest's own package convention.
- Generated tests may be represented primarily by generator commands/scripts rather than committed files.
- Samples/manual tests and generated tests have different roles; do not rewrite one as the other without evidence.

## File Roles

- Main/model solution: trusted full solution used as the answer oracle when appropriate.
- Correct alternative: expected to pass, useful for cross-checking.
- Wrong/TLE/RE/etc. solutions: evidence for test coverage; never use as oracles.
- Validator: validates input only.
- Checker: judges output against answer/validity rules.
- Interactor: owns the interactive protocol.
- Generator: creates inputs; it is not a validator.

## Non-Inference Rules

- Do not create a custom checker merely because one is common in exported packages.
- Do not infer scoring from checker presence.
- Do not assume every generated test is materialized in source control.
- Do not impose Codeforces-specific statement/test policy if the target contest says otherwise.
