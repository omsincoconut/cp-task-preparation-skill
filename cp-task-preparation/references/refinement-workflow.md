# Refinement Workflow

Use this reference when improving the `cp-task-preparation` skill from either active-session findings or post-session review. Keep updates canonical, retrieval-aware, and no larger than the evidence justifies.

## Mode Selection

- In-session refinement: the task/package session is still active and the user needs an immediate correction plus any reusable skill fix.
- Post-session refinement: the task session is complete enough for retrospective analysis, routing cleanup, regression checks, or architecture changes.

## In-Session Refinement

1. Fix or stabilize the current package/task behavior first.
2. Decide whether the issue is session-local or reusable across future tasks.
3. Classify the cause using `references/issue-taxonomy.md`: missing knowledge, retrieval failure, checklist failure, template failure, execution drift, or architecture issue.
4. Search existing canonical owners before writing new guidance.
5. Apply the smallest sufficient update: one owner edit, one operational checklist gate, or one template correction.
6. Continue the active task session and verify the current package still satisfies the requested outcome.

In-session updates should preserve workflow momentum. Prefer minimal targeted fixes, and do not redesign architecture mid-task unless the issue is clearly architectural and blocks correct work.

## Post-Session Refinement

1. Collect concrete findings from the completed session with evidence: prompt, actions, missed file, bad output, failed test, or duplicated guidance.
2. Classify each finding using `references/issue-taxonomy.md`.
3. Decide whether the finding is local one-off behavior, reusable methodology, architecture problem, retrieval problem, redundancy problem, checklist failure, template failure, or failure-mode-library gap.
4. Run the two end-of-session review tracks separately.
5. Search existing canonical owners before writing new guidance.
6. Prefer editing one canonical owner over duplicating the same instruction in `SKILL.md`, references, and checklists.
7. Add checklist items only when they are action gates.
8. Add failure-mode entries only when the lesson is reusable and mechanism-oriented.
9. Run `checklists/retrieval-audit.md` and targeted regression checks from `references/regression-and-benchmarking.md`.
10. Record what changed, why, and which future behavior should improve using `templates/refinement-report.md`.

Post-session refinement is the right place for broader routing redesign, redundancy cleanup, taxonomy growth, benchmark redesign, and regression analysis.

## End-Of-Session Review Tracks

Run both tracks, but do not mix their findings.

- Track A: Workflow / Package-Process Review covers reusable workflow, convention, packaging, verification, cleanup, routing, template, checklist, and refinement-process lessons. For each finding, record lesson, evidence, canonical owner, cause category, and status: already covered or should be added.
- Track B: Testcase-Generation Methodology Review covers testcase quality only: wrong-solution patterns, adversarial construction, generator-family ideas, subtask separation, benchmark/TL separation, unexpectedly passing weak solutions, multi-failure tests, and stronger legal tests that should have existed. Ignore pure workflow, formatting, folder, cleanup, or packaging issues unless they directly affect testcase quality. For each finding, record lesson, evidence, canonical owner, and status: already covered or should be added.

If either track has no new reusable lessons, say so directly.

## Reporting

Refinement reports should record the mode, trigger, current-package impact, reusable skill impact, cause category, canonical owner, update type, and retrieval/regression checks. Separate package correction from reusable skill correction when both occur.

## Escalation Rules

- If correct guidance existed but was not loaded, treat it as retrieval or routing before adding new methodology.
- If correct guidance existed but no gate caught the issue, prefer a checklist or template fix before adding prose.
- If a template causes repeated bad defaults, update the template and keep methodology in the owner reference.
- If the agent ignored clear guidance, classify execution drift; update routing or gates only when they were unclear or repeated failures show a pattern.
- Reserve new files, reference splits, and architecture redesign for post-session evidence of repeated or structural failures.

## Anti-Patterns

- Do not overreact to one local mistake without evidence that future tasks need skill-level guidance.
- Do not redesign architecture mid-task unless the failure is clearly architectural.
- Do not patch symptoms by adding another warning to `SKILL.md` when routing, retrieval, templates, or canonical ownership are the real issue.
- Do not add new policy when existing guidance was simply not loaded or enforced.
- Do not create a new reference when a focused edit to an existing owner would work.
- Do not turn checklists into methodology manuals.
- Do not duplicate a fix across owner, checklist, and template.
- Do not add anecdotal failure-mode entries that do not help construct future tests.

## Update Preference

Smallest safe update wins:

1. No skill change; document session-local lesson.
2. Edit one canonical owner.
3. Add one operational checklist gate.
4. Fix one reusable template default.
5. Add one failure-mode entry.
6. Split or add a reference only when retrieval quality would improve.
