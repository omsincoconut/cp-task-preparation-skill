---
name: cp-polyman-v3
description: "Build competitive programming problems with Polyman. Built for AI agents: machine-readable JSON output, compile caching (2s iterations), workspace documentation (CLAUDE.md/instructions/), Freemarker generator scripts, and headless workflows. Self-contained skill with Polygon basics, testlib patterns, and verification workflows."
---

# CP Polyman

Build competitive programming problems with Polyman. Built for AI agents with fast iteration, machine-readable output, and workspace documentation.

## When to Use This Skill

- Polyman workspaces with `CLAUDE.md`, `AGENTS.md`, `instructions/` directory
- Generator scripts are `.txt` files with Freemarker syntax
- Workspace has `Config.json` and `Config.schema.json`

**Self-contained**: This skill includes essential Polygon concepts (validators, checkers, generators) and doesn't require other skills.

## Important: Workspace Already Has Guidelines

**Polyman V3 workspaces created with `polyman new` already include comprehensive guidelines:**

```
your-problem/
├── CLAUDE.md                    # READ THIS FIRST - orientation
├── AGENTS.md                    # For other AI agents
├── Config.schema.json           # JSON Schema
└── instructions/                # Component-specific guides
    ├── working-rules.md         # How to behave, what "done" means
    ├── validator.md             # Validator guidelines
    ├── generators.md            # Generator guidelines
    ├── generator-script.md      # Script syntax guide
    ├── checker.md               # Checker guidelines
    ├── solutions.md             # Solution guidelines
    ├── manual-tests.md          # Manual test guidelines
    ├── statements.md            # Statement guidelines
    ├── config.md                # Config.json guide
    ├── cpp-performance.md       # C++ optimization tips
    └── commands/                # Per-command documentation
```

**This skill provides supplementary guidance, not duplicates.** Always read the workspace's own documentation first - it's tailored to the specific Polyman version and workspace structure.

## Quick Start

1. **Read workspace docs first**: The workspace's `CLAUDE.md` is your primary guide
2. **Follow working rules**: Read `instructions/working-rules.md` for behavior guidelines
3. **Use component guides**: When working on a component, read its specific guide in `instructions/`
4. **Use JSON output**: `polyman verify --json`, `polyman run <sol> --json`
5. **Parse structure**: Read JSON (`ok`, `failedStep`, `solutions[].tests[]`), don't scrape terminal
6. **Leverage cache**: Iterations are ~2s (first run ~9.5s)

## This Skill's Role

This skill provides:
- **Polyman CLI patterns** (flags, JSON parsing, cache usage)
- **Cross-workspace best practices** (testlib randomness, verification workflow)
- **Codeforces standards** (when targeting Codeforces contests)
- **Reference templates** (when workspace docs need examples)

The workspace's `instructions/` directory has the authoritative component-specific guidelines. Use this skill for CLI mechanics, Polygon standards, and patterns that apply across all Polyman workspaces.

## Key Features

### Machine-Readable Output

```bash
polyman verify --json
polyman run main --json
```

Parse the JSON structure:
- `ok` (boolean) - overall success
- `failedStep` (string|null) - which step failed
- `solutions[].matchesTag` (boolean) - solution got expected verdict
- `solutions[].tests[].verdict` - per-test result

Standard output = JSON, stderr = human logs.

### Compile Cache

**Performance**: First run ~9.5s, subsequent ~2.0s, single-file edit <1s

```bash
polyman cache status  # Show savings
polyman cache clear   # Wipe cache
polyman verify --no-cache  # Bypass cache
```

**Iteration strategy**:
- Edit one generator → recompiles only that file (<1s)
- Edit validator → `polyman test validator` (<1s)
- Use `--testset` or `--group` flags to regenerate only affected tests

### Workspace Documentation

Polyman workspaces include AI-oriented docs - read them:

```
CLAUDE.md              # Read first: orientation, pipeline, layout
AGENTS.md              # For other AI agents
instructions/
  ├── working-rules.md # How to behave, what "done" means
  ├── validator.md     # Read when working on validator
  ├── generators.md    # Read when working on generators
  ├── generator-script.md
  ├── checker.md
  └── ...
```

**Workflow**: Read `CLAUDE.md` and `working-rules.md` once for context. Open component-specific docs only when working on that component (keeps context small).

### Generator Scripts (Freemarker Format)

Generator scripts use Polygon's native Freemarker format in text files:

```freemarker
<#-- generators/gen-script.txt -->

<#-- @group small -->
<#list 1..10 as i>
gen-random -n 100 -seed ${i} > $
</#list>

<#-- @group large -->
gen-random -n 200000 -seed 1000 > $
gen-worst -n 200000 > $
```

**Syntax**:
- `> $` - next free index
- `> 5` - explicit index 5
- `> {40-41}` - multi-output (one generator creates tests 40 and 41)
- `<#-- @group name -->` - assign group
- `<#list 1..N as i>` - loop

**Config.json**:
```json
"testsets": [{
  "name": "tests",
  "generatorScript": { "scriptFile": "./generators/gen-script.txt" },
  "groupsEnabled": true,
  "groups": [{"name": "small"}, {"name": "large"}]
}]
```

See `templates/generator-script.ftl` for complete example.

### Headless Push

For non-interactive workflows:

```bash
polyman remote push . -y -n my-problem-slug
```

- `-y` - auto-confirm
- `-n <slug>` - problem name when creating new problem
- Saves `problemId` to Config.json

### C++23 Support

- Local: `-O2 -std=c++23`
- Override: `"cppStandard": "c++20"` in Config.json
- Remote: respects `sourceType` per file (e.g., `cpp.gcc14-64-msys2-g++23`)

## Typical Workflow

```bash
# 1. Read workspace orientation
cat CLAUDE.md instructions/working-rules.md

# 2. Write validator
# Read instructions/validator.md for workspace-specific rules
nano validator/validator.cpp
polyman test validator  # <1s with cache

# 3. Write generators
# Read instructions/generators.md for workspace-specific rules
nano generators/gen-random.cpp
nano generators/gen-script.txt
polyman generate --all --json

# 4. Validate all tests
polyman validate --all --json

# 5. Write solutions
# Read instructions/solutions.md for workspace-specific rules
nano solutions/main.cpp      # MA tag
nano solutions/brute.cpp     # TL tag
nano solutions/wrong.cpp     # WA tag

# 6. Run full verification
polyman verify --json

# 7. Parse JSON, fix failures, iterate (2s per iteration)

# 8. Push when verify passes
polyman remote push . -y -n problem-slug
```

**Key principle**: The workspace's `instructions/` files tell you WHAT to do for each component. This skill tells you HOW to use the Polyman CLI efficiently.

## Randomness Policy

All randomness must use `testlib.h`:
- Use `rnd.next()`, `rnd.wnext()`, etc.
- Don't use `rand()`, `<random>`, time-based seeds
- Pass `-seed` argument for deterministic replay

See `references/testlib-randomness.md` for details.

## Verification

Before push, check `references/verification-checklist.md`:
- [ ] `polyman verify --json` passes (`"ok": true`)
- [ ] All solutions match their tags (`"matchesTag": true`)
- [ ] Generator scripts are Freemarker `.txt` files
- [ ] Cache is working: `polyman cache status` shows time savings
- [ ] All randomness uses `testlib.h`

## References

### Essential References
- **Polygon basics**: `references/polygon-basics.md` — validators, checkers, generators, tags
- **Validation components**: `references/validation.md` — validator/checker/interactor design
- **Generator implementation**: `references/generators.md` — generator patterns and best practices
- **testlib randomness**: `references/testlib-randomness.md` — RNG patterns with testlib

### Polygon Package Guidelines
- **Package structure**: `references/polygon.md` — Polygon package inspection and wiring
- **Package conventions**: `references/package-conventions.md` — file roles, constraints, tests
- **Package consistency**: `references/package-consistency.md` — cross-file consistency audit
- **Testset integration**: `references/testset-integration.md` — test/group mapping

### Codeforces Standards
- **Codeforces rules**: `references/codeforces_polygon_rules.md` — official preparation standards
- **Statement macros**: `references/defs.toml` — standard LaTeX definition commands
- **Writing conventions**: `references/writing.md` — statement and documentation style

### Workflows
- **V2→V3 migration**: `references/v2-migration.md` — complete V2 to V3 migration guide
- **Final verification checklist**: `checklists/final-verification.md` — pre-push checklist
- **Verification checklist**: `references/verification-checklist.md` — detailed verification steps

### Tools & Templates
- Generator script template: `templates/gen-script.ftl`
- Windows line-ending probe: `scripts/probe-polyman-io.ps1`
- testlib header: `references/testlib.h`
