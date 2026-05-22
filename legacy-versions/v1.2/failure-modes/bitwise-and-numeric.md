# Bitwise And Numeric Failure Modes

Use this file for bit masks, fixed popcount, submask/supermask relations, least-significant-bit intervals, exact arithmetic, overflow, and aggregate yes/no conditions.

## Failure Mode: Fixed-Popcount Boundaries Are Missing

- Wrong assumption: Random bit values cover submask, popcount, and high-bit edge cases.
- Code/editorial smell: The solution classifies numbers by popcount, submask/supermask relation, or value class, but tests use only random masks.
- Small counterexample shape: Two masks differ by one high bit or have the same popcount but different submask relation.
- Scalable stress shape: Many values with fixed popcount near the maximum bit width, plus all-zero, all-one, and adjacent-power controls.
- Validation guardrails: Confirm values respect the statement's maximum and include exact duplicate masks when duplicates change the answer.
- Related files: `test-generation-harness.md`.

## Failure Mode: Submask/Supermask Existence Collapses To Equality

- Wrong assumption: The only easy case is making arrays equal, so non-equal valid pairs are rare or can be ignored.
- Code/editorial smell: A checker or solution only tests equality, or computes cost to equality before considering whether one value can be made a submask of another.
- Small counterexample shape: Two distinct numbers already form a submask/supermask pair.
- Scalable stress shape: Large arrays with many near-equal values but exactly one cheap submask/supermask pair hidden among expensive equality costs.
- Validation guardrails: Include duplicates, strict submasks, equal masks, and pairs requiring increments before the relation appears.
- Related files: `constructive.md`.

## Failure Mode: Least-Significant-Bit Contribution Starts At The Wrong Offset

- Wrong assumption: LSB contribution for a range can be applied uniformly from the left endpoint without tracking the offset inside the range.
- Code/editorial smell: The solution updates powers of two over `[l, r]` but forgets the `i - l + 1` phase or applies one global residue pattern.
- Small counterexample shape: Two equal-length intervals with different left endpoints produce different per-position contributions.
- Scalable stress shape: Cover all residues modulo powers of two using shifted intervals, full-range intervals, and single-point intervals.
- Validation guardrails: Test every residue class for each relevant power of two, and compare against a direct simulator for small `n`.
- Related files: `combinatorics-and-dp.md`.

## Failure Mode: Aggregate Yes/No Case Ignores The All-Same Designation

- Wrong assumption: Satisfying each group's lower bound is sufficient for a global yes answer.
- Code/editorial smell: The proof has one branch for mixed designated winners and a stricter branch when all winners are the same, but the code uses only lower-bound totals.
- Small counterexample shape: Every group has the same designated winner and the losing party has too many votes to place while preserving strict majorities.
- Scalable stress shape: Many small odd/even group sizes where lower-bound totals fit, but the required global vote difference is violated by one.
- Validation guardrails: Test all-zero and all-one designation strings separately from mixed strings, and include exact equality at the majority boundary.
- Related files: `test-generation-harness.md`.

## Failure Mode: Exact Average Or Sum Invariant Is Replaced By Floating Comparison

- Wrong assumption: An invariant stated as an average can be safely checked with floating point.
- Code/editorial smell: The solution divides the total by `n` and compares a decimal value instead of checking an integer sum equality.
- Small counterexample shape: Total is one away from the target multiple of `n`.
- Scalable stress shape: Large `n` and large values where floating precision or rounding hides a nonzero remainder.
- Validation guardrails: Test exact equality, one below, one above, and values large enough to require wide integer sums.
- Related files: `test-generation-harness.md`.
