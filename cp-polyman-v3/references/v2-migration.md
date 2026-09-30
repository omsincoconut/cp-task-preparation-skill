# Migrating from Polyman V2 to V3

**Breaking change**: Generator scripts moved from JSON arrays in Config.json to Freemarker text files.

## Quick Migration

1. **Check version**: `polyman --version` (should be 3.0.0+)

2. **Create script file**: `generators/gen-script.txt`

3. **Convert syntax**:
   
   **V2 (Config.json)**:
   ```json
   "commands": [
     {"generator": "gen-random", "args": "-n 10 -seed 1", "testIndex": 2},
     {"generator": "gen-random", "args": "-n 10 -seed 2", "testIndex": 3}
   ]
   ```
   
   **V3 (generators/gen-script.txt)**:
   ```freemarker
   gen-random -n 10 -seed 1 > 2
   gen-random -n 10 -seed 2 > 3
   ```

4. **Update Config.json**:
   
   **V2**:
   ```json
   "testsets": [{"name": "tests", "commands": [...]}]
   ```
   
   **V3**:
   ```json
   "testsets": [{
     "name": "tests",
     "generatorScript": {"scriptFile": "./generators/gen-script.txt"}
   }]
   ```

5. **Test**: `polyman verify --json`

## V3 Syntax

- `> $` — next free index
- `> 5` — explicit index
- `> {40-41}` — multi-output
- `<#-- @group name -->` — assign group
- `<#list 1..20 as i>` — loop

## Full Example

**V2 Config.json fragment**:
```json
"testsets": [{
  "name": "tests",
  "commands": [
    {"generator": "gen-sample", "args": "", "testIndex": 1},
    {"generator": "gen-random", "args": "-n 10 -seed 1", "testIndex": 2},
    {"generator": "gen-random", "args": "-n 10 -seed 2", "testIndex": 3}
  ]
}]
```

**V3 generators/gen-script.txt**:
```freemarker
<#-- @group samples -->
gen-sample > 1

<#-- @group small -->
<#list 1..2 as i>
gen-random -n 10 -seed ${i} > $
</#list>
```

**V3 Config.json fragment**:
```json
"testsets": [{
  "name": "tests",
  "generatorScript": {"scriptFile": "./generators/gen-script.txt"},
  "groupsEnabled": true,
  "groups": [{"name": "samples"}, {"name": "small"}]
}]
```

## New V3 Features to Use

- **JSON output**: `polyman verify --json` — parse structure, don't scrape terminal
- **Compile cache**: 2s iterations (vs 15s), check `polyman cache status`
- **Headless push**: `polyman remote push . -y -n slug`
- **C++23**: Default is now `-std=c++23`
- **Workspace docs**: Read `CLAUDE.md` and `instructions/` for guidance

## Verification

After migration:
1. `polyman --version` shows 3.0.0+
2. `polyman verify --json` passes
3. `polyman cache status` shows cache is working
4. Generator scripts are `.txt` files (no JSON commands in Config.json)
