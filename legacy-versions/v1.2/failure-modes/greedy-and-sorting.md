# Greedy And Sorting Failure Modes

Use this file for greedy ordering, replacement arguments, sorted local deltas, binary-search feasibility, and shared-resource mistakes.

## Failure Mode: Greedy Without Replacement Keeps An Expensive Choice

- Wrong assumption: Once an item is accepted by a quality or priority sweep, it should never be removed.
- Code/editorial smell: The solution sorts requirements and accepts the first feasible items, but does not keep a max-heap or equivalent structure for replacing a previously chosen expensive item with a cheaper one.
- Small counterexample shape: One high-priority expensive item is accepted early, then two lower-cost items become possible and together beat keeping the expensive one.
- Scalable stress shape: Many same-or-near quality items where every block offers one large requirement followed by many smaller requirements; the correct greedy repeatedly replaces the current largest chosen requirement.
- Validation guardrails: Preserve equal-quality ties and confirm the replacement is legal under the same resource threshold, not a later threshold.
- Related files: `data-structures.md`.

## Failure Mode: Equal-Key Replacement Is Accidentally Disabled

- Wrong assumption: Replacement only matters when the sorted primary key strictly decreases.
- Code/editorial smell: A replacement condition checks that the previous quality, coordinate, or key is strictly larger before swapping out a selected item.
- Small counterexample shape: Two candidates with the same required quality but different costs; the large-cost one is selected first and the smaller one appears later.
- Scalable stress shape: Large equal-key buckets with adversarial input order, forcing many replacements inside the bucket.
- Validation guardrails: Dry-run the exact sort comparator and stable/unstable tie behavior; include paired tests where only the tie order changes.
- Related files: `data-structures.md`, `test-generation-harness.md`.

## Failure Mode: Shared Resource Treated As Independent Per Target

- Wrong assumption: If each target is independently feasible, then the top `k` targets are feasible together.
- Code/editorial smell: The feasibility check computes usable resources for each item separately and never consumes, replaces, or globally accounts for shared capacity.
- Small counterexample shape: Two targets can each be satisfied alone by the same small resource pool, but cannot both be satisfied at once.
- Scalable stress shape: Many targets share the same high-quality resource tiers; independent feasibility says yes while global greedy or flow-style accounting says no.
- Validation guardrails: Include a small oracle that explicitly consumes resources, and test both `k = 1` and larger `k`.
- Related files: `data-structures.md`.

## Failure Mode: Binary-Search Feasibility Breaks Under Saturation

- Wrong assumption: Clamping multiplied capacities to a convenient integer maximum preserves the monotone predicate.
- Code/editorial smell: A binary search multiplies resource counts by days or repetitions, then casts or clamps to `int` before running feasibility.
- Small counterexample shape: A resource just above the clamp threshold is needed to distinguish two adjacent answers.
- Scalable stress shape: Maximal days and capacities where several resources saturate differently; compare with a wide-integer or capped-at-true-INF oracle.
- Validation guardrails: Cap at a value proven larger than every possible demand and keep the feasibility predicate monotone after capping.
- Related files: `bitwise-and-numeric.md`, `test-generation-harness.md`.

## Failure Mode: Local Deletion Delta Misses Endpoints Or Ties

- Wrong assumption: Removing an element is always a two-neighbor replacement.
- Code/editorial smell: The removal formula handles middle elements but gives endpoints special cases late or not at all.
- Small counterexample shape: Best deletion is the first or last element; add a tie where an endpoint and middle deletion both work.
- Scalable stress shape: Arrays with alternating large gaps plus flat prefixes/suffixes so endpoint deletion remains competitive under many sizes.
- Validation guardrails: Test `n = 2`, endpoint-only changes, middle changes, and equal best deltas.
- Related files: `combinatorics-and-dp.md`.
