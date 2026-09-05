# Graphs And State Failure Modes

Use this file for graph shape coverage, color/state walks, parity constructions, functional graphs, loops, tuples, and product-state reasoning.

## Failure Mode: Functional-Graph Cycle Constraint Is Ignored

- Wrong assumption: Every vertex or agent can be sent to the same target after a fixed number of moves.
- Code/editorial smell: The construction optimizes final distance but does not account for cycles forcing at least two distinct cells in a functional graph.
- Small counterexample shape: Two-node tail/cycle examples with odd and even move counts.
- Scalable stress shape: Maximum-size constructions that differ only by move parity and target-adjacent cycle placement.
- Validation guardrails: Test both odd and even move counts and verify no self-loop or forbidden edge violates the statement.
- Related files: `constructive.md`.

## Failure Mode: Graph Tests Use Only One Shape Family

- Wrong assumption: A line, star, cycle, complete graph, and random graph expose the same state behavior.
- Code/editorial smell: The solution relies on distance layers, color neighborhoods, or state transitions, but tests only random connected graphs.
- Small counterexample shape: Compare a path, star, triangle, and complete graph with the same number of vertices.
- Scalable stress shape: Generate shape families separately and preserve which state transition each family targets.
- Validation guardrails: Record connectedness, bipartiteness, same-layer edges, self-loop policy, and multiedge policy.
- Related files: `interactive-and-communication.md`, `../references/testcase-generation.md`.

## Failure Mode: Color-State Product Misses Loops Or Repeated Tuples

- Wrong assumption: Random edges cover all color/residue/state combinations.
- Code/editorial smell: The algorithm indexes states by colors, residues, tuples, or masks, but generators do not force repeated or loop-heavy cases.
- Small counterexample shape: A tiny graph with a loop-like transition or repeated tuple that revisits the same state with a different color history.
- Scalable stress shape: Dense state-product tests with controlled tuples, random tuples, and loop-heavy structures.
- Validation guardrails: Ensure the validator's loop/multiedge rules match the statement before promoting loop-style tests.
- Related files: `../references/testcase-generation.md`.

## Failure Mode: Parity Construction Tested Only At One Boundary

- Wrong assumption: A parity-based construction that works for one side of a boundary works for the other.
- Code/editorial smell: The solution branches on odd/even moves, index parity, or alternating colors, but tests only one parity.
- Small counterexample shape: Two otherwise identical cases with `k` odd and `k` even, or with endpoints of opposite parity.
- Scalable stress shape: Large cases where parity controls the unique optimal construction while all other parameters are fixed.
- Validation guardrails: Pair odd/even controls and verify the answer or checker-valid construction changes in the expected way.
- Related files: `constructive.md`, `combinatorics-and-dp.md`.
