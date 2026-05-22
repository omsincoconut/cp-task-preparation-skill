# Workflow And Uncertainty

Use this reference to keep package preparation evidence-based.

## End-To-End Execution

- Start with inventory before moving files or writing generated artifacts.
- Record source-to-target mappings for every renamed or reclassified file.
- Keep platform-specific materials separated.
- Generate outputs only after identifying a trusted oracle.
- Run validation, checker, stress, and compile checks appropriate to the task.
- Finish with explicit notes about missing components and residual risk.

## Uncertainty Language

Use direct labels:

- `high confidence`: confirmed by metadata, code role, or user instruction.
- `medium confidence`: likely based on location and content, but not independently verified.
- `low confidence`: plausible but uncertain; do not rely on it for outputs or scoring.
- `unknown`: not enough evidence.

## What To Ask

Ask the user when:

- Multiple plausible official solutions exist and none is tagged.
- Scoring semantics cannot be derived from available scorer/grader code.
- A package includes conflicting platform materials.
- Missing files are required to complete the requested workflow.

## What To Document

- Missing validator/checker/model/brute/generator/scorer.
- Partial solutions and their confirmed scope.
- Ignored source folders and why they were ignored.
- Test renaming maps.
- Whether outputs were preserved or regenerated.
- Any package behavior that cannot be represented by `scorer.txt` alone.
