# CMS Test Integration

This reference maps a platform-neutral `cp-test-plan/v1` plan into the target CMS loader/task configuration.

## Loader first

CMS task semantics and authoring filesystem layout are separate. Determine the exact repository/importer convention before choosing filenames or metadata. Preserve a supplied contest convention rather than inventing a universal CMS zip layout.

## Mapping

- Logical case IDs -> loader-specific testcase filenames/IDs.
- Logical groups/subtasks -> score-type/scorer/dataset membership as required by the contest setup.
- Platform-neutral construction recipes -> concrete generated/materialized tests using the repository's tooling.
- Oracle policy -> answer files, grader/model path, or manager-driven result as appropriate to task type.

For Communication, ordinary `.out` files may be unnecessary because the manager can emit the testcase outcome. Do not fabricate answer files merely to resemble Batch tasks.

## Semantic boundary

Do not redesign adversarial intent while mapping. If a CMS task-type or loader restriction makes a planned case impossible, report it and revise the semantic Test Plan deliberately.
