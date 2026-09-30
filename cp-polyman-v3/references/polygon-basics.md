# Polygon Package Basics

Essential Polygon concepts for Polyman workspaces.

## Problem Package Structure

A Polygon problem package consists of:
- **Validator**: Checks input format and constraints
- **Checker**: Determines if contestant output is correct
- **Interactor** (optional): For interactive problems
- **Generators**: Create test inputs programmatically
- **Solutions**: Reference solutions with expected verdicts
- **Tests**: Input files (manual or generated)
- **Statements**: Problem description in various languages

## Solution Tags

Solutions are tagged with expected behavior:

- **MA** (Main/Accepted) - Correct solution, passes all tests
- **OK** - Another correct solution
- **WA** (Wrong Answer) - Incorrect algorithm
- **TL** (Time Limit) - Correct but too slow
- **ML** (Memory Limit) - Uses too much memory
- **RE** (Runtime Error) - Crashes or fails
- **PE** (Presentation Error) - Output format issues
- **RJ** (Rejected) - Should not compile or fail checker

Tag each solution in Config.json so `polyman verify` can check they behave correctly.

## Validators

Validators read input and either accept (valid) or reject (invalid).

**Must do:**
- Read exact bytes (all input, nothing left)
- Check all constraints from statement
- Call `registerValidation(argc, argv)` at start
- Use `inf.readInt(1, n, "n")` style validation
- Check sum constraints, structural properties, EOF

**Must not:**
- Depend on what generators happen to produce
- Skip checking any statement constraint
- Leave unread input

Validators use testlib.h API. Every generated test must validate.

## Checkers

Checkers determine if contestant output is correct.

**Standard checkers** (most common):
- `std::wcmp.cpp` - token-by-token comparison
- `std::ncmp.cpp` - single integer
- `std::fcmp.cpp` - floating point with epsilon
- `std::rcmp4.cpp` - multiple tokens, case-insensitive

**Custom checkers** needed when:
- Multiple valid outputs exist
- Need to validate constructive solutions
- Floating point with custom tolerance
- Semantic validation beyond token matching

Checkers read:
1. Input file (`inf` stream)
2. Jury answer (`ans` stream)
3. Contestant output (`ouf` stream)

Return verdict: `quitf(_ok, ...)`, `quitf(_wa, ...)`, etc.

## Generators

Generators create test inputs programmatically.

**Best practices:**
- One generator per test family/mechanism
- Use command-line parameters (validated)
- All randomness via testlib `rnd`
- Pass `-seed` for deterministic replay
- Output valid input per validator rules

**Example**:
```cpp
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int seed = opt<int>("seed");
    
    println(n);
    for (int i = 0; i < n; i++) {
        println(rnd.next(1, 1000000));
    }
}
```

## Test Organization

**Manual tests**: Hand-written, explicit indices
- Samples (index 1, 2, ...) with `useInStatements: true`
- Edge cases you write by hand

**Generated tests**: Created by generator script
- Use `> $` for auto-indexing
- Organize into groups (small, large, edge, etc.)
- Script runs in order, creates tests sequentially

**Groups**: Logical organization of tests
- Enable with `"groupsEnabled": true` in Config.json
- Assign with `<#-- @group name -->` in script
- Useful for subtasks, scoring, debugging

## Config.json Structure

```json
{
  "problemName": "my-problem",
  "validators": [{"name": "validator", "source": "./validator/validator.cpp"}],
  "checker": {"name": "checker", "source": "./checker/checker.cpp"},
  "generators": [
    {"name": "gen-random", "source": "./generators/gen-random.cpp"},
    {"name": "gen-worst", "source": "./generators/gen-worst.cpp"}
  ],
  "solutions": [
    {"name": "main", "source": "./solutions/main.cpp", "tag": "MA"},
    {"name": "brute", "source": "./solutions/brute.cpp", "tag": "TL"},
    {"name": "wrong", "source": "./solutions/wrong.cpp", "tag": "WA"}
  ],
  "testsets": [{
    "name": "tests",
    "generatorScript": {"scriptFile": "./generators/gen-script.txt"},
    "manualTests": [
      {"input": "./manual/tests/01-sample.in", "index": 1, "useInStatements": true}
    ],
    "groupsEnabled": true,
    "groups": [
      {"name": "samples"},
      {"name": "small"},
      {"name": "large"}
    ]
  }]
}
```

## Verification Flow

1. **Generate tests**: `polyman generate --all --json`
2. **Validate tests**: `polyman validate --all --json` (runs validator on all tests)
3. **Run solutions**: `polyman run <solution> --json` (tests one solution)
4. **Full verify**: `polyman verify --json` (generates, validates, runs all solutions)

`polyman verify` is the pre-push gate - it must pass.

## Remote Operations

**Register credentials** (once):
```bash
polyman remote register <api-key> <api-secret>
```

**Push to Polygon**:
```bash
polyman remote push . -y -n problem-slug
```

This creates/updates the problem on Polygon, uploads all files.

**Never commit API credentials** to version control.

## Common Issues

**Validator rejects generated tests**: Generator produces invalid input
- Fix: Generator must respect validator's constraints

**Solution tagged WA but passes**: Wrong solution is actually correct
- Fix: Improve test coverage or fix solution

**Solution tagged MA but fails**: Main solution has bug
- Fix: Debug solution or adjust test

**Checker accepts wrong output**: Checker too lenient
- Fix: Strengthen checker validation

**CRLF vs LF**: Windows line endings cause issues
- Use `scripts/probe-polyman-io.ps1` to diagnose
- Ensure consistent line endings in repository
