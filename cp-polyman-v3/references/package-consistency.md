# Polygon Package Consistency

This is a package-integration audit, not a second testcase-design methodology.

Check the same limits and semantics where they are copied across:

- statement;
- validator;
- generator arguments/bounds;
- problem metadata and testset/group configuration;
- checker/interactor protocol where relevant;
- main/correct solution constants only as evidence, never as the source of truth by default.

When a mismatch changes which inputs are legal or which solutions a suite should separate, return that issue to `cp-test-case`. When the mismatch is only package wiring or stale metadata, fix it here.
