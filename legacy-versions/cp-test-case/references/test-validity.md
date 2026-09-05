# Test Validity

This skill owns the semantic question “is this promoted input legal for the problem?” It does not own implementation of a Polygon validator, CMS manager, checker, grader, or interactor.

## Validity basis

Build one explicit validity model from the strongest available evidence:

1. statement input format and global constraints;
2. subtask promises and aggregate/sum bounds;
3. semantic structural requirements (tree, permutation, connectivity, uniqueness, non-emptiness, protocol state, and similar conditions);
4. confirmed executable restrictions that are intended to be part of the problem rather than accidental implementation limits.

When statement and executable enforcement disagree, record the mismatch before promoting tests. Do not quietly treat a permissive validator as permission to violate the statement.

## Audit targets

For every promoted family, check relevant:

- scalar min/max and indexing ranges;
- total/sum constraints across cases or queries;
- structural graph/tree/string/grid properties;
- uniqueness/order/permutation promises;
- per-subtask promises;
- communication/interactive hidden-state restrictions that affect legal testcase construction.

## Boundary to platform skills

`cp-test-case` describes the validity requirement in the Test Plan. `cp-polygon` implements/checks Polygon validators and generation wiring. `cp-cms` implements/checks CMS managers, graders, validators, and loader-specific restrictions.
