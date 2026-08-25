# CMS Scoring Integration

CMS task types produce a per-testcase **outcome**; a configured score type then aggregates testcase outcomes into the submission score. Preserve this distinction.

## Core CMS score types

CMS provides score types such as `Sum`, `GroupMin`, `GroupMul`, and `GroupThreshold`, with parameters configured in CMS. A repository/importer may encode those parameters in its own files or metadata; the filesystem representation is not universal CMS syntax.

## Loader/repository-specific scoring files

If the target repository explicitly uses a `scorer.txt` convention matching `templates/scorer.txt`, preserve that convention. Do **not** introduce `scorer.txt` merely because the target is CMS. A named importer, contest repository, or existing task is the authority for how group membership, points, dependencies, and score-type parameters are serialized.

For the bundled legacy/contest-style `scorer.txt` template, entries look like:

```text
[
[POINTS, "001|002|003"]
]
```

Use that shape only when the target convention requires it. Preserve overlapping group membership when that convention represents subtasks by testcase lists.

## Custom/per-test outcomes

A checker or Communication manager may emit fractional testcase outcomes. Do not flatten that behavior into binary pass/fail groups if the configured score type depends on the fractional value.

## Expected outputs

Generate ordinary answer files only when the task type/loader requires them and a trusted oracle exists. Communication tasks may instead derive each testcase outcome directly from the manager.
