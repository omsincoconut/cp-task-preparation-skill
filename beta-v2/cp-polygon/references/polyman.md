# Polyman

Polyman is a third-party CLI for developing competitive-programming problems locally and synchronizing supported components with Codeforces Polygon. This reference is based on the Polyman repository and user/technical guides checked on 2026-08-25. The installed CLI may differ, so use `polyman --help` and subcommand help for version-sensitive flags.

## Detecting a Polyman Workspace

Typical signs:

```text
Config.json
solutions/
generators/
validator/
checker/
statements/
testsets/ or generated test material
```

A Polyman workspace is not identical to a raw Polygon package. Treat `Config.json` as local orchestration/configuration and verify how it maps to Polygon before push.

## Install and Bootstrap

Documented installation uses npm:

```bash
npm install -g polyman-cli
polyman --version
```

Create a workspace and obtain testlib when appropriate:

```bash
polyman new <directory>
cd <directory>
polyman download-testlib
```

Do not overwrite a project-pinned `testlib.h` automatically. Compare versions or preserve the existing file unless the user asks for an update.

## Local Workflow

Common commands documented by Polyman include:

```bash
polyman list solutions
polyman list generators
polyman list testsets
polyman list checkers
polyman generate --all
polyman validate --all
polyman run <solution-name> --all
polyman test <component>
polyman verify
```

Use narrower `--testset`, `--group`, or `--index` selectors when supported by the installed version and useful for iteration.

`polyman verify` is the preferred local pre-push gate because it validates configuration, compiles components, generates/validates tests, and exercises configured solutions/checkers according to the tool's workflow.

## Config.json

Polyman's configuration describes problem metadata plus solutions, generators, validator, checker, and testsets. Preserve established fields and use the installed tool's schema/guide rather than inventing keys.

Solution tags documented by Polyman include `MA` for the main correct solution and tags such as `OK`, `WA`, `TL`, `TO`, `ML`, `RE`, `PE`, and `RJ` for expected behavior. Preserve imported tags when evidence supports them; do not relabel unknown submissions casually.

## Polygon Remote Operations

Documented workflow:

```bash
polyman remote register <api-key> <api-secret>
polyman remote list
polyman remote pull <problem-id> <directory>
polyman remote push <problem-id> <directory>
polyman remote commit <problem-id> "message"
polyman remote package <problem-id> <type>
```

Some versions accept `.` or selective component flags. Verify the installed command help before execution.

### Safety Rules

- Never put API keys or secrets in the skill output, repository, logs, or examples.
- Do not run `remote push`, `remote commit`, or package-build operations unless the user explicitly requests the remote mutation.
- Pull can overwrite or normalize local files; inspect status/back up local work when needed.
- Run `polyman verify` before push unless the user explicitly directs otherwise.
- After push, Polygon changes may still require a separate commit; confirm status rather than assuming persistence.

## Package Builds

Polyman documentation lists Polygon package types such as `standard`, `linux`, `windows`, and `full`. Treat those as tool/version-specific values; query `polyman remote package --help` before invoking.

## Sources Consulted

- Polyman GitHub repository README and GUIDE.md.
- Polyman technical documentation and user guide.
- Codeforces testlib page for the role of testlib in problem-setting auxiliary programs.
