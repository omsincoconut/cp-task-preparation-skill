# Interactive And Communication Failure Modes

Use this file for interactive queries, non-adaptive hidden data, communication/run-twice tasks, and protocol verification.

## Failure Mode: Alternating-Bit Query Recovery Forgets Carries

- Wrong assumption: Each bit can be recovered independently from alternating-mask queries.
- Code/editorial smell: The solution reads query sums as per-bit counts without carrying information from lower positions.
- Small counterexample shape: Two low bits produce a carry that changes the interpretation of the next bit.
- Scalable stress shape: Values with alternating `01`/`10` patterns, adjacent runs of ones, and maximum-bit carries.
- Validation guardrails: Simulate the exact interactor arithmetic and include transcript tests where lower-bit carries affect higher-bit classification.
- Related files: `bitwise-and-numeric.md`.

## Failure Mode: Non-Opposite Corner Assumption Is Not Verified

- Wrong assumption: Any two far or corner-like references uniquely identify grid positions.
- Code/editorial smell: The interactive solution derives coordinates from two distance arrays but does not prove the corners are non-opposite or consistently oriented.
- Small counterexample shape: A small grid where opposite corners leave a symmetry ambiguity.
- Scalable stress shape: Query candidate corners on square grids and rectangular-like encodings, with hidden targets on symmetry axes.
- Validation guardrails: Verify the chosen reference points break symmetry before using distance equations; test minimal `n` separately.
- Related files: `graphs-and-state.md`, `../references/testcase-generation.md`.

## Failure Mode: Run-Twice Encoding Assumes Bipartite Edges Only

- Wrong assumption: Neighbor colors always differ by exactly one distance layer.
- Code/editorial smell: The first run colors by distance modulo a small base, while the second run treats every edge as if it connects adjacent layers.
- Small counterexample shape: A graph with an odd cycle or same-layer edge where a vertex sees fewer color classes than expected.
- Scalable stress shape: Compare lines, stars, cycles, complete graphs, and random graphs under the same run-twice strategy.
- Validation guardrails: Test second-run local views, not just first-run colors; include cases where every neighbor has the same color.
- Related files: `graphs-and-state.md`.

## Failure Mode: Query Budget Ignores Constant Terms And Repeated Self-Queries

- Wrong assumption: A query count like `3n^2 + O(n)` is automatically within the limit for all small and large cases.
- Code/editorial smell: The implementation queries all cells multiple times, then adds a candidate search phase without subtracting duplicates or self-queries.
- Small counterexample shape: Minimal `n` where candidate sets overlap heavily and duplicate queries are easy to count by hand.
- Scalable stress shape: Maximum `n` with worst-case candidate counts, instrumenting the interactor to count every query.
- Validation guardrails: Preserve transcript logs and assert the exact query limit in the interactor or checker tests.
- Related files: `../references/testcase-generation.md`.
