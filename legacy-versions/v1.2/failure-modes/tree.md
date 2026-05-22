# Tree Failure Modes

Use this file for tree paths, Euler tours, LCA handling, ancestor contributions, and tree-shape stress construction.

## Failure Mode: LCA Endpoint And Non-Endpoint Cases Are Mixed

- Wrong assumption: A path query can treat the LCA uniformly whether it is an endpoint or a strict ancestor.
- Code/editorial smell: Euler-window path encoding uses one interval for endpoint-LCA cases and a separate extra contribution for non-endpoint-LCA cases.
- Small counterexample shape: Use a root with two child leaves and compare queries `(root, leaf)` against `(leaf, other_leaf)`.
- Scalable stress shape: Make many leaf-to-leaf queries share a heavy root LCA while endpoint movement stays small.
- Validation guardrails: Confirm which queries set the extra-LCA field after the implementation's own indexing and DFS order.
- Related files: `offline-queries.md`.

## Failure Mode: Heavy Ancestor Contribution Is Not Charged To Path Movement

- Wrong assumption: If a heavy ancestor is its own block or is rarely crossed by endpoints, its payload cannot dominate runtime.
- Code/editorial smell: A large ancestor is inserted as an auxiliary path contribution rather than by normal endpoint movement.
- Small counterexample shape: Star tree with root carrying a large payload and repeated leaf-to-leaf queries.
- Scalable stress shape: Give the root or another shared ancestor maximum legal payload and make many queries require it as the strict LCA.
- Validation guardrails: Separate endpoint-crossing counts from auxiliary insertion counts.
- Related files: `data-structures.md`, `offline-queries.md`.

## Failure Mode: Tree Shape Masks Or Exposes Different Costs

- Wrong assumption: A chain, star, and shallow branching tree are interchangeable stress cases.
- Code/editorial smell: The proof depends on Euler interval length, LCA location, subtree size, or repeated ancestor sharing, but tests use only one tree shape.
- Small counterexample shape: Compare a chain, a star, and a root-child-hub tree on the same query pattern.
- Scalable stress shape: Use stars for shared root LCAs, chains for deep ancestor/DFS behavior, and hub subtrees for same-block alternating LCA patterns.
- Validation guardrails: Report the intended tree shape and the internal DFS/Euler facts it creates.
- Related files: `test-generation-harness.md`.

## Failure Mode: Local Recursion Stack Artifact Treated As Official Failure

- Wrong assumption: A stack overflow observed locally is an official counterexample.
- Code/editorial smell: A deep-recursive DFS fails under the local shell or OS stack limit, but the grading environment has different stack policy.
- Small counterexample shape: Deep chain that crashes only with the local stack limit.
- Scalable stress shape: Maximum-depth chain for diagnostics, not for official promotion unless the judge has the same limit.
- Validation guardrails: Classify as local-environment artifact unless official stack limits make it valid. Do not report it as WA/TLE/RE for the real grader.
- Related files: `test-generation-harness.md`.
