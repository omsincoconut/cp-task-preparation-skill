# Testcase Generation

Use this reference to design tests, generators, and coverage from constraints, solution analysis, and failure-mode mechanisms.

## Test Design Loop

1. Extract constraints, subtasks, task type, and trusted oracle path.
2. Load `references/solution-analysis.md` when wrong, partial, or slow solutions exist.
3. Derive testcase knobs from the target algorithm's real work: ordering, block decomposition, grouping, cache state, data-structure update cost, output volume, and memory layout.
4. Build small exhaustive or hand-checkable tests before scaling.
5. Add structured boundary tests that are as strong as each subtask's constraints permit.
6. Add adversarial tests for wrong and slow solutions, preferring one test that breaks several wrong ideas or subtasks when possible.
7. For every intended subtask separation, use the strongest legal construction available inside that subtask before accepting that a partial, slow, or wrong implementation should pass it.
8. Recheck adversarial and max-stress cases against full statement constraints, not only the local validator or public grader.
9. Add randomized tests only after structured coverage exists and only when they add coverage not already provided by stronger concrete cases.
10. Stress accepted/model against brute on small domains.
11. Document generator intent, subtask membership, wrong-solution targets, statement-validity checks, and the solution-by-subtask verdict matrix in `markdowns/test_description.md`.

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

- Start from the proof obligation: correctness failure, complexity gap, memory pressure, output volume, or broad coverage.
- For performance failures, identify the actual bottleneck mechanism before generating: memory bandwidth, cache locality, allocation churn, comparator cost, branch prediction, hash behavior, output volume, recursion depth, or repeated data-structure rebuilds.
- Model the solution's internal representation when it matters. If a solution sorts queries, compresses values, assigns blocks, marks heavy objects, or rewrites endpoints, write a dry-run checker that reproduces that internal order before trusting the construction.
- Force the bottleneck directly. For slow-solution tests, target the exact repeated operation.
- Within each subtask, prefer the most adversarial legal distribution for the targeted mechanism. Do not leave an easy/random distribution in place when a stronger legal construction exists and preserves the subtask's official promise.
- Test against optimized slow and borderline implementations when available; large random tests are not a substitute for mechanism-targeted stress.
- Keep a tunable parameter for each claimed cause: expensive object size, affected query count, group count, endpoint spread, tie density, output size, and total input size.
- Build families with below-threshold, at-threshold, and above-threshold variants when the solution branches on a threshold.
- Use diversity deliberately. If top stress cases are all one family, report that instead of implying broad coverage.
- Regenerate from the source generator when a constraint or harness mistake is found. Do not patch promoted tests or logs by hand unless the patch itself is part of the documented generator flow.
- After regeneration, check that documented generation scripts, executable scripts, promoted tests, and testcase ordering/parameters remain synchronized.
- Generate expected outputs only after statement-level validity passes and the trusted solution path is identified.
- Preserve generator commands, seeds, parameters, dry-run summaries, validator output, statement-scan output, and benchmark logs near the generated tests.

## Generator Source Rules

- Use `testlib.h` randomness (`registerGen`, `rnd.next`, and related helpers) as the default randomness source in Polygon-style generators.
- In Polygon generators, include testlib as `#include "testlib.h"` and compile with include paths.
- Source global limits from the package's canonical constraints owner, such as `polygon/constraints.h`, instead of duplicating max sizes in every generator.
- Avoid `rand()`, `random_shuffle`, `<random>`, and custom RNGs unless a task-specific reason is documented.
- Prefer separate generator files for distinct testcase characteristics, such as `gen_random.cpp`, `gen_equal.cpp`, `gen_tree.cpp`, or `gen_chain.cpp`.
- A generator may support multiple descriptive, mechanism-oriented parameterizations, but avoid one monolithic file containing unrelated testcase mechanisms or opaque mode-number dispatch.
- Keep generators scaling-friendly: accept descriptive parameters, validate them against canonical limits, and hardcode only highly specific adversarial shapes whose rigidity is intentional.
- Provide `gen_script.txt` as a Freemarker-style generation script when preparing Polygon tests, and keep generator intent clear from filenames and parameters.
- If the statement has samples, place those sample tests first in promoted testcase order.

## Domain Patterns

- Graphs: disconnected/connected boundaries, trees, cycles, multiedge policy, self-loop policy, dense/sparse, color/state coverage.
- Bitwise: zero, all ones, powers of two, adjacent powers, fixed popcount, max value, mixed high/low bits.
- Constructive: impossible cases, multiple valid answers, minimal construction, maximal construction, ties.
- DP/combinatorics: tiny cases with brute oracle, repeated values, modulo boundaries, long homogeneous segments.
- Interactive: query-limit edges, invalid query behavior, non-adaptive hidden cases, transcript sanity.

## Generator Intent

Infer intent from filenames, generation commands, validator constraints, and known wrong-solution targets. Preserve intent, not local naming style.
