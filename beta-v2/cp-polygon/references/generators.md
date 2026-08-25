# Polygon Generators

This reference owns **Polygon-side implementation** of a semantic testcase plan.

## Default randomness policy

Unless the user or target-contest rules explicitly state otherwise, **all randomness must come from the bundled `testlib.h`**. Do not use `rand()`, `srand()`, `<random>`, custom RNGs, platform RNG calls, or time-based entropy.

For C++ generators, the default pattern is:

- `#include "testlib.h"`;
- `registerGen(argc, argv, 1)` or the package-required compatible registration;
- `rnd` helpers from testlib for every randomized choice;
- command arguments and seeds/replay behavior preserved through the Polygon generation workflow.

If an existing package pins another `testlib.h`, preserve that version unless the user explicitly requests replacement. User/contest instructions override this default.

## Semantic-plan realization

Consume `contracts/test-plan-v1.md`:

- map logical case IDs to Polygon test numbers;
- map logical groups/subtasks to Polygon test groups/testsets as supported by the target package;
- implement construction recipes as generators or manual tests;
- preserve deterministic replay and documented parameters;
- keep generation commands readable enough to recover test intent.

The Polygon skill may optimize implementation, but it must not silently weaken the semantic purpose of a planned adversarial case.

## Generator design

- Prefer one generator source per coherent mechanism/family rather than unrelated numeric modes in one monolith.
- Use descriptive command-line parameters and validate them against package limits.
- Keep manual/sample tests distinct from generated tests.
- Run every generated input through the official/intended validator before promotion.
- Preserve the package's actual Polygon generation representation; do not invent Freemarker syntax when the package uses a different supported/exported representation.
