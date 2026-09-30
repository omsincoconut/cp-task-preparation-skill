# Polyman V3 Verification Checklist

Run before `polyman remote push`:

## Core Verification

- [ ] `polyman --version` shows 3.0.0 or higher
- [ ] `polyman verify --json` passes with `"ok": true`
- [ ] All solutions match expected tags: `"matchesTag": true` in JSON output
- [ ] Parse JSON output programmatically, don't scrape terminal

## Generator Scripts

- [ ] Scripts are Freemarker `.txt` files (not JSON arrays in Config.json)
- [ ] Script syntax correct: `> $`, `> 5`, `<#list>`, `<#-- @group -->`
- [ ] Generator names match `Config.json` generators without file extension
- [ ] All randomness uses `testlib.h` (no `rand()`, `<random>`, time-based seeds)
- [ ] Seeds passed via `-seed` argument for deterministic replay

## Compile Cache

- [ ] `polyman cache status` shows cache is working
- [ ] Time savings visible (first run ~9.5s, subsequent ~2s)
- [ ] `.polyman/cache/` excluded from version control

## Solutions

- [ ] Main solution (MA tag) passes all tests
- [ ] Wrong solutions (WA tag) fail as expected
- [ ] Slow solutions (TL tag) timeout on large tests
- [ ] All solution tags match actual behavior in JSON output

## Tests

- [ ] All generated tests validate successfully
- [ ] Manual/sample tests at correct indices
- [ ] Group assignments correct (samples, small, large, edge, etc.)
- [ ] Test numbering has no gaps or conflicts

## Configuration

- [ ] `Config.json` syntax valid (check with editor/schema)
- [ ] `Config.schema.json` present for validation
- [ ] C++ standard correct (`"cppStandard": "c++23"` or override set)
- [ ] `sourceType` set for each file if pushing to Polygon

## Workspace Documentation

- [ ] `CLAUDE.md` and `instructions/` reflect current implementation (if modified)
- [ ] `working-rules.md` guidelines followed

## Security

- [ ] No API keys, secrets, or credentials in files
- [ ] No unnecessary binaries or build artifacts
- [ ] `.polyman/cache/` not included in commits

## Headless Push

If using non-interactive push:
- [ ] `-y` flag for auto-confirm
- [ ] `-n <slug>` flag for problem name (when creating new problem)
- [ ] `polyman remote push . -y -n <slug>` syntax correct
