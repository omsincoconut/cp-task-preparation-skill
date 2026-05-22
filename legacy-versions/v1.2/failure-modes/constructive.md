# Constructive Failure Modes

Use this file for constructive-output tasks, permutation construction, case tables, partial solutions, and incremental subtask paths.

## Failure Mode: Partial Constructive Strategy Is Mistaken For Full

- Wrong assumption: A construction that earns partial score or solves a constrained board/state also solves the unconstrained task.
- Code/editorial smell: The solution halts in a non-final location, handles a fixed subset of special values, or assumes special items start in allowed positions.
- Small counterexample shape: Move one special item outside the partial solution's expected region.
- Scalable stress shape: Enumerate all positions of the special items under the full constraints and compare partial and full verdicts.
- Validation guardrails: Keep the subtask boundary explicit, and do not use partial solutions as full output oracles.
- Related files: `test-generation-harness.md`.

## Failure Mode: Insertion Path Misses Special Off-Path Positions

- Wrong assumption: Sorting or repairing along one path covers every misplaced item.
- Code/editorial smell: The constructive proof follows a snake/insertion path but has special cases for center cells, endpoints, or off-path numbers.
- Small counterexample shape: Put a special item in a cell adjacent to, but not on, the normal insertion path.
- Scalable stress shape: Generate every legal placement of special items around the path boundary and require the construction to route them back.
- Validation guardrails: Verify both the final arrangement and the stopping position or scoring state.
- Related files: `test-generation-harness.md`.

## Failure Mode: Lexicographic Construction Ignores Fixed-Bit Prefix Blocks

- Wrong assumption: Any permutation maximizing the objective also satisfies the lexicographically minimum requirement.
- Code/editorial smell: The construction gets the right objective by using all high-popcount prefixes, but iterates the free bits in arbitrary order.
- Small counterexample shape: `n = 3` or `n = 4`, where a valid high-score permutation can be compared lexicographically by hand.
- Scalable stress shape: For each prefix length, fix the required low bits and iterate all remaining bits in the order the lexicographic rule demands.
- Validation guardrails: Check both the objective value and lexicographic minimality against brute force for small `n`.
- Related files: `bitwise-and-numeric.md`.

## Failure Mode: Constructive Checker Accepts The Right Shape But Wrong Certificate

- Wrong assumption: If a constructive output resembles the intended pattern, it is valid.
- Code/editorial smell: The checker verifies size or format but not operation legality, path reachability, strict inequalities, or final state.
- Small counterexample shape: Output has the correct number of objects but one operation violates the local rule.
- Scalable stress shape: Randomly perturb one step in otherwise valid certificates and ensure the checker rejects it.
- Validation guardrails: Checker must simulate the construction or verify every local invariant, not just match high-level counts.
- Related files: `test-generation-harness.md`.
