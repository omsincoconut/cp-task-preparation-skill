# Failure-Mode Library Index

Load this library after identifying a task family, solution family, wrong assumption, or performance bottleneck. Start here, then open only the relevant topic files.

## Topic Files

- `offline-queries.md`: Offline sorting, Mo-style ordering, block assignment, cached state, external path contributions, and threshold branches.
- `tree.md`: Euler tours, LCA endpoint cases, ancestor contributions, star/chain constructions, and local recursion-stack artifacts.
- `data-structures.md`: Frequency buckets, mode maintenance, large-object updates, lazy cleanup, duplicate payloads, ties, and rebuild costs.
- `greedy-and-sorting.md`: Greedy replacement, sort tie handling, shared resources, binary-search feasibility, local-delta deletion, and saturation.
- `bitwise-and-numeric.md`: Fixed-popcount, submask/supermask, least-significant-bit intervals, aggregate equality, overflow, and exact average checks.
- `constructive.md`: Constructive-output validation, incremental subtask paths, special positions, partial-vs-full solutions, and case-table coverage.
- `interactive-and-communication.md`: Query design, non-adaptive hidden data, run-twice encodings, communication protocols, and query-limit edges.
- `graphs-and-state.md`: Graph shape diversity, color-state walks, parity constructions, loops, tuples, residues, and state-product coverage.
- `combinatorics-and-dp.md`: Contribution formulas, parity terms, max/min range reductions, gate-order DP traps, and exhaustive small oracles.

## Use Pattern

1. Identify the algorithmic family and suspected failure mechanism.
2. Load the closest topic file only.
3. Pick entries that match the code or editorial smell.
4. Turn the small shape into an oracle-backed test.
5. Scale the shape only after statement-level validation and trusted output generation are settled.
6. Record new reusable lessons in the topic file and update this index only when adding new topic files.
