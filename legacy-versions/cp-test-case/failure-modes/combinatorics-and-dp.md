# Combinatorics And DP Failure Modes

Use this file for contribution formulas, parity correction terms, dynamic programming transitions, max/min range reductions, and exhaustive small oracles.

## Failure Mode: Closed-Form Contribution Drops The Parity Term

- Wrong assumption: A quadratic contribution formula over counts has no parity correction.
- Code/editorial smell: The derivation simplifies a floor/ceil product or subsequence score but omits the odd/even remainder.
- Small counterexample shape: Binary strings with count difference `1` and `2`, compared against exhaustive subsequence enumeration.
- Scalable stress shape: Many queries over all-zero, all-one, balanced, and off-by-one count strings.
- Validation guardrails: Keep an all-small generator and brute enumerator for every closed-form combinatorics formula.
- Related files: `../references/testcase-generation.md`.

## Failure Mode: Max-Min Range Formula Misses Equal Or Zero Prefixes

- Wrong assumption: A maximum absolute subarray sum can be tested with only positive or strictly alternating values.
- Code/editorial smell: The solution transforms values by parity and reduces to `max(prefix)-min(prefix)`, but ignores zero entries and repeated prefix values.
- Small counterexample shape: A short array with zeros or equal prefix sums where multiple intervals tie for the maximum.
- Scalable stress shape: Long segments of zeros and alternating signs, plus monotone controls, to stress stack or range max/min aggregation.
- Validation guardrails: Include ties for max/min prefix positions and compare against a quadratic oracle for small arrays.
- Related files: `graphs-and-state.md`, `../references/testcase-generation.md`.

## Failure Mode: Gate-Order DP Chooses Immediate Gain Instead Of Future Multiplier

- Wrong assumption: Added resources should go to the side that is currently smaller or immediately larger.
- Code/editorial smell: The correct recurrence reasons about future multiplication potential, but the implementation greedily allocates by current lane size or current gate only.
- Small counterexample shape: A small sequence where adding to the currently worse side is optimal because that side reaches the earlier larger multiplier.
- Scalable stress shape: Long gate sequences with repeated additions before diverging multipliers and tie-breaking multipliers far ahead.
- Validation guardrails: Test equal current values, equal next multipliers, and delayed tie-breaks; watch for overflow at maximum gate counts.
- Related files: `greedy-and-sorting.md`.

## Failure Mode: DP State Bound Follows The Sample, Not The Subtask

- Wrong assumption: A small constraint in an early subtask implies the same observable structure as the full task.
- Code/editorial smell: The editorial's early-subtask DP has `O(N^2Q)` or exhaustive state transitions, while the final task requires a different monotone or greedy structure.
- Small counterexample shape: A case just beyond the early DP's intended size where pruning or greedy assumptions change the answer.
- Scalable stress shape: Increase the dimension that the subtask DP squares or enumerates while holding the visible structure constant.
- Validation guardrails: For every subtask solution, record the exact constraint under which it is an oracle and do not use it for full tests.
- Related files: `greedy-and-sorting.md`, `../references/solution-analysis.md`.
