# CMS Communication Task Type

This reference summarizes CMS Communication behavior from current CMS 1.6.dev0 documentation researched on 2026-08-25, plus the supplied Elevator example.

## When to Use Communication

Use Communication when the testcase input, or part of it, must remain unavailable to contestant code for at least part of evaluation. Typical designs include queries about hidden data or incremental/partitioned information flow.

## Process Model

CMS runs:

- one admin-controlled **manager**, which reads the testcase input and communicates with contestant code; and
- one or more **contestant processes**, optionally compiled together with an admin-provided `stub.<language>`.

The manager and contestant processes run in separate sandboxes so contestant code cannot directly read the hidden testcase input.

## Manager Contract

The deployed admin manager executable is named `manager` in CMS task configuration/import formats that use the standard manager name.

For N contestant processes:

- CMS provides N FIFO pairs to the manager, one pair per contestant process;
- each contestant process receives its own communication endpoints, either as arguments or via redirected standard input/output depending on task configuration;
- each contestant process also receives its 0-based process index as an additional argument when multiple processes are used;
- the task's time accounting applies across the contestant processes according to CMS Communication semantics.

For the common one-process case, the manager reads testcase input from stdin and receives two FIFO filenames, from and to the contestant process, in that order according to the CMS documentation.

Do not hardcode a FIFO argument convention from an example without reconciling it against the exact CMS version/configuration and any wrapper used by the contest.

## Stub Contract

A `stub.<language>` can be compiled with contestant code. The stub should own low-level communication and expose the intended contestant function/API. Keep the public API minimal; do not expose hidden testcase data or manager-only details.

If multiple languages are supported, provide and verify the required stub/header equivalents for those languages.

## Standard Manager Output

For Communication in the documented CMS model, the manager reports:

- on stdout: a single-line floating-point outcome;
- on stderr: a single-line contestant-facing message.

CMS recognizes special localized-message tokens such as `translate:success`, `translate:wrong`, and `translate:partial` in manager-style output in documented versions. A contest may intentionally use explicit messages instead; follow the target policy.

If a contestant process itself fails, CMS can override/ignore the manager's result and assign failure according to task-type behavior.

## Scoring

The manager's outcome is not automatically the final task score; the configured CMS score type aggregates testcase outcomes. Keep per-test manager scoring and subtask/group scoring separate in documentation.

## Local Testing

Build a local harness that reproduces as much of the deployed protocol as possible:

1. compile the contestant source with the intended stub;
2. launch the expected number of contestant processes;
3. connect each process to the manager using the same channel direction/order as deployment;
4. feed the manager the testcase input only;
5. test clean EOF, early contestant exit, malformed contestant messages, duplicate/invalid actions, and maximum communication volume;
6. verify manager output is in the deployed CMS format;
7. ensure no hidden data leaks through arguments, environment, files, diagnostics, or deterministic ordering unintended by the statement.

## Multi-Process Pitfalls

- Process index can become an unintended communication side channel if the protocol lets a strategy infer hidden scenario order from call order/index.
- Different contestant processes cannot be assumed to communicate directly.
- FIFO-heavy protocols can spend significant time in communication itself; benchmark the protocol overhead, not only contestant algorithm work.
- Deterministic replay is useful for debugging, but hidden scenario ordering must still match the problem's security/game semantics.
- Ignore `SIGPIPE` or handle closed channels deliberately where appropriate so one failed process does not crash the manager unexpectedly.

## Elevator Example

`examples/elevator/` demonstrates a supplied EJOI 2026 multi-process Communication task source layout:

- `system/manager.cpp` reads hidden testcase data and owns scoring/protocol enforcement.
- `system/stub.cpp` receives a process index and calls contestant functions from `elevator.h`.
- there are `N + 2` contestant-side processes in the example: one for each floor role plus a rooftop role, reflected by the manager's FIFO argument count.
- `contestant/grader.cpp` is a local contestant-facing simulator; it is not the deployed CMS manager.

Use the example for role/protocol reasoning only; do not copy its constants, scoring, filenames, or process count into unrelated tasks.

## Sources Consulted

- CMS Task types, current documentation: https://cms.readthedocs.io/en/latest/Task%20types.html
- CMS External contest formats: https://cms.readthedocs.io/en/latest/External%20contest%20formats.html
