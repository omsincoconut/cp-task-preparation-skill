# Testcase Generation

Use this reference to design tests, generators, and coverage from constraints and false solutions.

## Test Design Loop

1. Extract constraints, subtasks, and task type.
2. Identify solution invariants and likely wrong assumptions.
3. Write or sketch plausible wrong solutions before finalizing adversarial coverage.
4. For each important solution, decide the intended verdict for each subtask.
5. Build small exhaustive or hand-checkable tests.
6. Add structured boundary tests that are as strong as each subtask's constraints permit.
7. Add adversarial tests for wrong and slow solutions, preferring one test that breaks several wrong ideas or subtasks when possible.
8. Add randomized tests only after structured coverage exists and only when they add coverage not already provided by stronger concrete cases.
9. Stress accepted/model against brute on small domains.
10. Document generator intent, subtask membership, wrong-solution targets, and the solution-by-subtask verdict matrix in `test_description.md`.

## Generator Categories

- Samples: exact statement examples.
- Tiny exhaustive: all or many small cases for oracle comparison.
- Boundary: min/max values, empty-like cases, singletons, duplicates, all equal.
- Structured: monotone arrays, stars/chains/complete graphs, balanced trees, grids, fixed-popcount values.
- Adversarial: targets a known false solution or fragile invariant.
- Random: broad distribution for unanticipated interactions.
- Max stress: near limits for complexity and memory.

## Generator Source Rules

- Use `testlib.h` randomness (`registerGen`, `rnd.next`, and related helpers) as the default and only randomness source in Polygon-style generators.
- Avoid `rand()`, `random_shuffle`, `<random>`, and custom RNGs unless a task-specific reason is documented.
- Prefer separate generator files for distinct testcase characteristics, such as `gen_random.cpp`, `gen_equal.cpp`, `gen_tree.cpp`, or `gen_chain.cpp`.
- A generator may support multiple parameterizations, but avoid one monolithic file containing all testcase logic.
- Provide a Freemarker-style generation script when preparing Polygon tests, and keep generator intent clear from filenames and parameters.

## Domain Patterns

- Graphs: disconnected/connected boundaries, trees, cycles, multiedge policy, self-loop policy, dense/sparse, color/state coverage.
- Bitwise: zero, all ones, powers of two, adjacent powers, fixed popcount, max value, mixed high/low bits.
- Constructive: impossible cases, multiple valid answers, minimal construction, maximal construction, ties.
- DP/combinatorics: tiny cases with brute oracle, repeated values, modulo boundaries, long homogeneous segments.
- Interactive: query-limit edges, invalid query behavior, non-adaptive hidden cases, transcript sanity.

## Generator Intent

Infer intent from:

- Filename hints such as `all_small`, `random`, `fixed_popcount`, `chain`, `star`, `max`, `stress`.
- Command arguments in `problem.xml` or scripts.
- Validator constraints.
- Which wrong solution a test appears to target.

Do not require exact generator names in new packages. Preserve intent, not local naming style.

## Wrong Solutions And Countertests

- Store incorrect implementations under `wrong/` when they guide test design.
- Create `wrong_solution.md` describing the incorrect idea, why it fails, the testcase pattern that breaks it, and which generated tests target it.
- For each wrong or partial solution, explicitly determine which subtasks should expose the issue and whether current tests actually do so.
- If a wrong solution can fail a smaller subtask under the official constraints, include a small-subtask countertest instead of relying only on full-constraint tests.
- If a wrong solution cannot fail a subtask because the subtask constraints make the bug impossible, document that reason.
- Prefer lightweight countertest sets: a single concrete testcase that breaks multiple wrong solutions is better than several narrowly targeted cases.
- Common categories include greedy mistakes, overflow, off-by-one errors, invalid monotonicity, incorrect DP transitions, precision issues, and missing edge cases.
