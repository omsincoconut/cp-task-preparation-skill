# CMS Communication Verification Checklist

- `Communication` is intentionally selected rather than `Interactive`/Batch/library.
- Hidden testcase input is read only by admin-controlled code that should see it.
- Number of contestant processes and each process index agree with configuration/stub behavior.
- Manager/stub communication endpoints and message framing agree in every supported language.
- Flush/termination/EOF and contestant early-exit behavior are handled.
- Malformed or out-of-protocol contestant communication yields a controlled outcome rather than a manager crash.
- Manager emits the CMS-required outcome/message protocol and does not leak hidden input.
- No unnecessary ordinary answer files/checkers are invented when the manager owns the result.
