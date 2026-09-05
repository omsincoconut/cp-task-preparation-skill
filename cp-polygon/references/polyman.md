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

### Efficient Iteration, Especially on Windows

Do cheap, focused checks while iterating, then run one full `polyman verify` immediately before the first remote push or after a cross-cutting change. Do not repeat a full generation, validation, and solution run merely because `verify` already covers it.

- Validator-only change: `polyman test validator`, then validate the affected materialized tests.
- Generator or script change: generate the affected group/index, validate that group, and run the main solution only there.
- Main-solution change: run the main solution on a representative small case and the affected group; keep slow brutes outside the configured full suite.
- Shared limits, testset layout, checker, or line-ending changes: use the full gate once because they affect multiple roles.

Keep strict-input data file-based. Do not feed multiline test data through PowerShell pipelines or capture generator output through shell variables. When line endings matter, inspect a tiny materialized input as bytes before broad regeneration. A validator intended for both local Windows tests and Polygon builds should deliberately accept both LF and CRLF, or the package must enforce the one required format at every boundary. Do not force generator binary output until a probe establishes that the target package expects it.

For a new Polyman/Polygon environment, first compile and run one tiny generator, validator, and MA path. This discovers include paths, testlib behavior, output line endings, and compiler restrictions before expensive generation or answer production.

On Windows, use the bundled probe with a known generator-backed test index:

```powershell
& "<cp-polygon-skill-dir>\scripts\probe-polyman-io.ps1" -Workspace . -Testset tests -Index 2 -Solution main
```

It regenerates only that index, prints CRLF/LF byte counts for the materialized input, validates it, and runs the selected solution. It makes local generated-test/output changes but performs no remote operation. Choose the index from the testset's existing generator mapping; do not use a sample when probing generator behavior.

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

### Remote Diagnostics and Package Completion

Polyman versions may collapse individual remote upload errors into warnings. After a failed or partial push, inspect the remote problem before retrying all components. Reproduce one failing component through the installed SDK only when necessary, print the API error without credentials, fix the identified boundary, and retry that component. Typical boundaries are header/resource classification, source compiler compatibility, statements not represented in `Config.json`, and generated-test metadata that must be applied after saving the script.

For generated Polygon tests, save and read back the script before assigning groups or points. Use API operations that update group/point metadata without replacing generated test input; do not turn generated tests into manual inputs just to set metadata.

Package construction is asynchronous. After `remote package`, poll the package state until it is `READY` or `FAILED`; report the failure comment and investigate it rather than treating a queued build as success. A successful package build with verification is the remote completion signal.

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
