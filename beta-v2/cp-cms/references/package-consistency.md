# CMS Package Consistency

This audit owns CMS integration consistency, not deep testcase design.

Check copied limits and protocol assumptions across:

- statement;
- loader/task metadata;
- validators or testcase parser;
- grader/manager/stub/public headers;
- checker and score configuration;
- solution constants only as supporting evidence.

For Communication also reconcile process count, process indices, hidden-input ownership, pipe/FIFO/stdin-stdout wiring, termination rules, and manager-output semantics.

When a mismatch changes legal testcase semantics or adversarial obligations, return it to `cp-test-case`; when it is package wiring/configuration drift, fix it here.
