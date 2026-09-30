# Competitive Programming Task Preparation Skills

AI workflows for preparing competitive-programming tasks and packages for Polygon and CMS.

---

## Skills

### `cp-polyman-v3/`

**For Polyman V3 workspaces**

- Built for AI agents with machine-readable JSON output
- Compile caching (2s iterations vs 15s)
- Workspace documentation (CLAUDE.md/instructions/)
- Freemarker generator scripts
- Headless workflows

Use when workspace has `CLAUDE.md`, `AGENTS.md`, and `instructions/` directory.

### `cp-polygon/`

**For native Polygon packages**

- General Polygon package lifecycle
- Validators, checkers, interactors
- Test planning and integration
- Statement preparation
- Works with Polyman V2 or native Polygon

Use for native Polygon packages or Polyman V2 workspaces.

### `cp-cms/`

**For CMS packages**

- Makes files such as graders, stubs, checkers, managers, and sample graders

---

## Usage

1. Load the appropriate skill for your workflow
2. Call the skill in the directory where you're building your package
3. Provide task statement and requirements

---

## Legacy Versions

`legacy-versions/` contains files related to old versions of the skills.

---

## Notes

I do not own [testlib](https://github.com/MikeMirzayanov/testlib), [polyman](https://github.com/HamzaHassanain/polyman), [Codeforces Polygon rules](http://codeforces.com/r/authors-polygon-rules), or defs.toml. They are included for easier use.
