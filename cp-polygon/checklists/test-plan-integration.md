# Polygon Test Plan Integration Checklist

- Test Plan contract is `cp-test-plan/v1` or its fields are otherwise recoverable.
- Every logical case/group has a concrete Polygon mapping or an explicit unresolved note.
- Randomized generators use only `testlib.h` unless an override is documented.
- Seeds/parameters/replay requirements survive the mapping.
- Generated inputs pass the intended validator.
- Group membership, dependencies, points, and numbering preserve semantic intent.
- Expected outputs are generated only through the trusted full oracle path.
- Existing package IDs are preserved unless renumbering was requested.
