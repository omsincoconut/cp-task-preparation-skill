# Data-Structure Failure Modes

Use this file for frequency tables, mode queries, linked buckets, lazy cleanup, large updates, duplicated payloads, and rebuild-heavy structures.

## Failure Mode: Large Payload Toggle Hidden In O(1) State Change

- Wrong assumption: Toggling an object is O(1) because the object is conceptually one node, bucket, or item.
- Code/editorial smell: The toggle loops over all values stored inside that object.
- Small counterexample shape: One object stores many distinct values while all other objects store one harmless value.
- Scalable stress shape: Put the maximum legal payload on the repeatedly toggled object and trigger it in many queries or updates.
- Validation guardrails: Check total payload constraints as well as object count constraints.
- Related files: `offline-queries.md`, `tree.md`.

## Failure Mode: Mode Maintenance Has Hidden Scan Or Cleanup Cost

- Wrong assumption: Maintaining a mode is constant-time because frequency updates are local.
- Code/editorial smell: Answer extraction scans buckets, linked lists, heavy-color lists, or repeatedly cleans stale entries.
- Small counterexample shape: Create many colors tied near the maximum frequency and verify answer extraction behavior.
- Scalable stress shape: Put many colors above the implementation's heavy threshold or create dense frequency buckets that churn on updates.
- Validation guardrails: Accept any valid mode when checking correctness, but measure extraction/update work separately for performance.
- Related files: `test-generation-harness.md`.

## Failure Mode: Duplicate Values Inside One Object Break Counting Assumptions

- Wrong assumption: Each object contributes at most one copy of a value.
- Code/editorial smell: Updates assume set-like behavior, but the input permits repeated values inside the same node, bag, interval, or record.
- Small counterexample shape: One object contains the same value multiple times, and a query includes that object once.
- Scalable stress shape: Repeat a small color set many times inside large payload objects to stress frequency increments and mode ties.
- Validation guardrails: Confirm whether the statement allows duplicates within one object's list. If not, the test is invalid.
- Related files: `tree.md`.

## Failure Mode: Rebuild Cost Repeats Across Groups

- Wrong assumption: A data structure built for one group can be rebuilt many times without dominating because each group is small.
- Code/editorial smell: The solution runs a separate pass per heavy object, bad LCA, bucket, component, or color class and clears/rebuilds shared state.
- Small counterexample shape: Two or three groups each require a nontrivial pass over similar ranges.
- Scalable stress shape: Maximize the number of groups just above the grouping threshold and spread queries to force repeated sweeps.
- Validation guardrails: Count groups, per-group range movement, and cleanup cost under the actual branch condition.
- Related files: `offline-queries.md`.

## Failure Mode: Priority Queue Tracks Accepted Count But Not Returned Capacity

- Wrong assumption: A heap of accepted items is only needed to count selected items, not to restore capacity during replacement.
- Code/editorial smell: The implementation pops a previous item but forgets to add its resource back before taking the cheaper replacement, or stores the wrong key in the heap.
- Small counterexample shape: Accept one large requirement, fail on a smaller requirement, and require the freed capacity to make the replacement feasible.
- Scalable stress shape: Repeated replacement chain where each accepted item is slightly cheaper than the previous one, forcing capacity restoration many times.
- Validation guardrails: Track resource balance after each replacement and include equal-key cases from `greedy-and-sorting.md`.
- Related files: `greedy-and-sorting.md`.

## Failure Mode: Range-Query Capacity Structure Ignores Lowest-Quality Consumption

- Wrong assumption: Consuming any available resource from a qualifying quality tier is equivalent.
- Code/editorial smell: An alternative greedy says to take the lowest-quality usable resource first, but the data structure updates an arbitrary or highest tier.
- Small counterexample shape: One high-quality resource is wasted on a low-requirement item, leaving a later high-requirement item impossible.
- Scalable stress shape: Many quality tiers with near-identical counts, where wrong tier selection accumulates into several lost acceptances.
- Validation guardrails: Add tests that expose both quality ordering and count exhaustion; verify the range-query update chooses the intended tier.
- Related files: `greedy-and-sorting.md`.
