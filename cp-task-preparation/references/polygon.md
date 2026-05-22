# Polygon Reference

Use for Polygon packages and Codeforces-style package materials.

## What Polygon Materials Usually Mean

- `problem.xml` records problem metadata, tests, files, solutions, and generation commands.
- `tests/` may contain samples, pretests, generated inputs, answers, or only partial material.
- Full generated tests may not be materialized in the repository.
- `files/`, `scripts/`, and generator sources can be more informative than stored tests.
- `checker.cpp` may exist for exact-output tasks because of workflow conventions.

## Normalization

- Keep Polygon files under `polygon/`.
- Put generation commands in `polygon/scripts/` when preserving helper scripts.
- Put generated or preserved Polygon tests in `polygon/tests/`.
- Keep Polygon test IDs stable unless the user asks for renaming.
- Use `01`/`01.a` as the default style for new Polygon tests.
- Generators should include `testlib.h` as `#include "testlib.h"` and be compiled with include paths instead of parent-directory includes.
- Provide `gen_script.txt` for generated Polygon suites, using Freemarker-style comments and `$` automatic testcase numbering.
- After regenerating tests, verify `gen_script.txt`, executable scripts, promoted tests, and testcase ordering/parameters describe the same suite.

## Inspection Steps

1. Read `problem.xml` for test commands, solution tags, checker/interactor references, and scoring hints.
2. Inspect `gen_script.txt` and scripts for generator intent.
3. Inspect validators before trusting generated tests.
4. Inspect checker/interactor only to understand output protocol, not to infer CMS behavior.
5. Read solution `.desc` files and accepted/rejected tags as evidence for false-solution analysis.

## Common Pitfalls

- Do not copy Codeforces folder names into CMS/OI conventions.
- Do not treat accepted-submission directories as package structure examples.
- Do not assume generated binaries are source of truth when source exists.
- Do not require materialized full outputs if the workflow uses generators and scripts.
