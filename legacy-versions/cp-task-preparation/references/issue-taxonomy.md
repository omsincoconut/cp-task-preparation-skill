# Issue Taxonomy

Use this reference during skill refinement to classify findings and choose ownership.

## Categories

- `convention error`: wrong platform, file, layout, or naming assumption. Owner: `package-conventions.md`, `polygon.md`, `cms.md`, or `local-grader.md`.
- `retrieval failure`: right guidance existed but was not loaded. Owner: `SKILL.md` routing or an index.
- `testcase weakness`: weak coverage or generator design. Owner: `testcase-generation.md`.
- `adversariality gap`: missed mechanism attack. Owner: `testcase-generation.md` or a specific failure-mode file.
- `solution misclassification`: model, brute, wrong, partial, slow, or unknown role confusion. Owner: `solution-analysis.md`.
- `verification weakness`: missing compile, validation, checker, stress, or final gate. Owner: checklist first; reference only if methodology is missing.
- `statement-validator mismatch`: statement validity and validator behavior diverged. Owner: `statement-validation.md`.
- `benchmarking issue`: bad TL/ML measurement or reporting. Owner: `benchmarking.md`.
- `scorer semantics issue`: subtask, overlap, scorer text, scorer code, or partial-credit confusion. Owner: `scoring.md`.
- `uncertainty failure`: overclaiming, hallucinated semantics, weak confidence labels. Owner: `epistemics-and-uncertainty.md`.
- `architecture redundancy`: same concept repeated in multiple places. Owner: remove duplicates and update routing.
- `routing problem`: `SKILL.md` or an index points too broadly or unclearly.
- `missing methodology`: no current canonical owner covers a reusable process. Add to the narrowest existing reference before creating a file.
- `checklist failure`: correct method existed but no operational gate caught it.
- `template failure`: correct method existed but a reusable template failed to encode or enforce it.
- `failure-mode-library gap`: reusable algorithmic or construction mechanism is missing from `failure-modes/`.
- `execution drift`: agent ignored the workflow. Fix routing or checklists only if repeated or caused by unclear instructions.

## Ownership Questions

For each finding, answer:

- Is it reusable across tasks?
- Did correct guidance already exist?
- Was the problem missing knowledge, bad retrieval/routing, weak enforcement, bad template default, or execution drift?
- Which single file should own the fix?
- Would adding text increase retrieval precision or just add another warning?
