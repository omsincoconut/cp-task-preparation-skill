# Testcase Generation

Use this reference to design tests, generators, and coverage from constraints and false solutions.

## Test Design Loop

1. Extract constraints, subtasks, and task type.
2. Identify solution invariants and likely wrong assumptions.
3. Derive testcase knobs from the target algorithm's real work: ordering, block decomposition, hidden grouping, cache state, data-structure update cost, output volume, and memory layout.
4. Write or sketch plausible wrong solutions before finalizing adversarial coverage.
5. For each important solution, decide the intended verdict for each subtask.
6. Build small exhaustive or hand-checkable tests.
7. Add structured boundary tests that are as strong as each subtask's constraints permit.
8. Add adversarial tests for wrong and slow solutions, preferring one test that breaks several wrong ideas or subtasks when possible.
9. Recheck every adversarial or max-stress case against the full statement constraints, not only the local validator or public grader.
10. Add randomized tests only after structured coverage exists and only when they add coverage not already provided by stronger concrete cases.
11. Stress accepted/model against brute on small domains.
12. Document generator intent, subtask membership, wrong-solution targets, statement-validity checks, and the solution-by-subtask verdict matrix in `test_description.md`.

## Generator Categories

- Samples: exact statement examples.
- Tiny exhaustive: all or many small cases for oracle comparison.
- Boundary: min/max values, empty-like cases, singletons, duplicates, all equal.
- Structured: monotone arrays, stars/chains/complete graphs, balanced trees, grids, fixed-popcount values.
- Adversarial: targets a known false solution or fragile invariant.
- Mechanism-isolating: holds most variables constant while forcing one algorithmic behavior, such as comparator order, cache churn, repeated rebuilds, or mode/frequency maintenance.
- Paired controls: differs from an adversarial test by one or two parameters to confirm the intended mechanism is what changed the outcome.
- Random: broad distribution for unanticipated interactions.
- Max stress: near limits for complexity and memory.

## Construction Methods

- Start from the proof obligation. Decide whether the test is meant to disprove correctness, demonstrate a complexity gap, maximize constant factors, or only provide broad coverage.
- Model the solution's internal representation when it matters. If a solution sorts queries, compresses values, assigns blocks, marks heavy objects, or rewrites endpoints, write a dry-run checker that reproduces that internal order before trusting the construction.
- Force the bottleneck directly. For slow-solution tests, target the exact repeated operation, such as rescanning a large node, rebuilding a large structure, moving a Mo endpoint across expensive elements, or scanning many mode buckets.
- Keep a tunable parameter for each claimed cause: size of expensive object, number of affected queries, number of groups, endpoint spread, tie density, output size, and total input size.
- Build families, not just one file. Include below-threshold, at-threshold, and above-threshold variants when the solution branches on a threshold.
- Use diversity deliberately. Top stress cases should ideally represent different mechanisms; if the top files are all the same family, report that instead of implying broad coverage.
- Add small oracle-backed versions before scaling up. A tiny version should make the intended path or answer checkable; the large version should preserve the same mechanism at limit scale.
- Regenerate from the source generator when a constraint or harness mistake is found. Do not patch promoted tests or logs by hand unless the patch itself is part of the documented generator flow.
- Generate expected outputs only after statement-level validity passes and the trusted solution path is identified.
- Preserve generator commands, seeds, parameters, dry-run summaries, validator output, statement-scan output, and benchmark logs near the generated tests.

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
- Countertests must remain legal after every statement constraint is enforced. If a stress family depends on a missing validator check or invalid loophole, discard or regenerate it under the real constraints.
- Preserve the formal or complexity argument behind a countertest alongside empirical logs; empirical behavior alone is not enough to explain a false solution.
- For each wrong or partial solution, explicitly determine which subtasks should expose the issue and whether current tests actually do so.
- If a wrong solution can fail a smaller subtask under the official constraints, include a small-subtask countertest instead of relying only on full-constraint tests.
- If a wrong solution cannot fail a subtask because the subtask constraints make the bug impossible, document that reason.
- Prefer lightweight countertest sets: a single concrete testcase that breaks multiple wrong solutions is better than several narrowly targeted cases.
- Common categories include greedy mistakes, overflow, off-by-one errors, invalid monotonicity, incorrect DP transitions, precision issues, and missing edge cases.
