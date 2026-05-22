# Offline Queries Failure Modes

Use this file for solutions that reorder queries, use Mo-style movement, split queries into groups, cache temporary contributions, or rely on block thresholds.

## Failure Mode: Cached External Contribution Only Helps Adjacent Equal Keys

- Wrong assumption: If an expensive external contribution, such as an LCA outside the active range, repeats often, caching it against the previous query makes its cost sublinear.
- Code/editorial smell: The answer path temporarily inserts and removes an object per query, then a patch only skips the work when the current query has the same extra object as the immediately previous sorted query.
- Small counterexample shape: Create two query types in the same left block whose sorted order alternates between expensive object `A` and cheap object `B`.
- Scalable stress shape: Make `A` carry many values and force `Theta(Q)` alternations after the actual offline sort, so the cached value changes on nearly every query.
- Validation guardrails: Simulate the solution's final sorted order, not input order. Confirm the extra contribution values alternate after sorting.
- Related files: `tree.md`, `test-generation-harness.md`.

## Failure Mode: Offline Sort Order Invalidates Input-Order Intuition

- Wrong assumption: Queries adjacent in the input remain adjacent enough for locality, caching, or grouping arguments.
- Code/editorial smell: Complexity reasoning discusses neighboring queries without reproducing the comparator, block assignment, or odd-even order used by the implementation.
- Small counterexample shape: Generate a handful of queries whose input order has long runs of one type, but whose sorted order interleaves incompatible types.
- Scalable stress shape: Spread right endpoints across the comparator's traversal direction while keeping left endpoints in the same or targeted blocks.
- Validation guardrails: Add a dry-run checker that computes internal query intervals, block IDs, sort keys, and first several sorted query classes.
- Related files: `test-generation-harness.md`.

## Failure Mode: Heavy Object Scanned Outside Claimed Movement Bound

- Wrong assumption: The Mo endpoint movement bound covers all expensive updates.
- Code/editorial smell: The implementation also performs per-query temporary toggles, recomputation, or add/remove work that is not part of normal endpoint movement.
- Small counterexample shape: Keep endpoint movement cheap while every query triggers the same large temporary object outside the active window.
- Scalable stress shape: Use maximum allowed payload on the temporary object and many queries requiring it, especially when it is not classified into a separate safe path.
- Validation guardrails: Count the expensive operation directly. Do not accept a proof that only bounds interval movement.
- Related files: `data-structures.md`, `tree.md`.

## Failure Mode: Threshold Boundary Misclassified

- Wrong assumption: A threshold branch behaves the same at `<`, `<=`, `>`, and `>=` boundaries.
- Code/editorial smell: The explanation says "larger than threshold" or "at least threshold" but the code uses a different comparison.
- Small counterexample shape: Generate three versions with size `T - 1`, `T`, and `T + 1`.
- Scalable stress shape: Place many objects exactly on the implemented boundary and many just across it, then verify which path they enter.
- Validation guardrails: Derive `T` from code constants, not from the editorial phrase. Include a dry-run count of objects per branch.
- Related files: `test-generation-harness.md`.
