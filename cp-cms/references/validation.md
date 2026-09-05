# CMS Validation Components

## Roles

- Validator: validates testcase input before/independently of contestant execution.
- Checker/comparator: evaluates produced output for task types/configurations that use output comparison.
- Grader: source compiled with contestant code, commonly exposing a library-style API and handling I/O.
- Communication stub: source compiled with contestant code that mediates manager communication.
- Communication manager: admin-controlled executable that reads hidden input, communicates with contestant process(es), enforces protocol, and emits per-test outcome/message.

Do not merge these roles just because a local development harness performs several of them.

## Validation Rules

- Statement constraints, validator behavior, manager parsing, and local grader parsing must agree.
- Validate structural and global/sum constraints, not only per-field ranges.
- Communication manager must reject malformed contestant protocol messages safely and without leaking hidden data.
- Public grader/stub diagnostics should not reveal hidden official-test information.
- For library tasks, contestant-facing headers should remain minimal and stable.
