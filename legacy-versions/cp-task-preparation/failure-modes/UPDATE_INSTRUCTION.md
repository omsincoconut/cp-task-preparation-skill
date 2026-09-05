# Failure-Mode Library Update Instructions

Use this file when skill refinement identifies a reusable `failure-mode-library gap`.

## Update Rules

- Add a failure-mode entry only when the lesson describes a reusable algorithmic or construction mechanism.
- Prefer an existing topic file when the mechanism belongs to a current family.
- Add a new topic file only when at least three expected entries share a distinct family or an existing file would become too broad.
- Keep entries mechanism-oriented rather than anecdotal.
- Do not add entries that merely restate checklist items, benchmarking rules, validator rules, or one task's story.

## Entry Format

```markdown
## Failure Mode: <name>

- Symptom: <code or editorial smell>
- Mechanism: <why the wrong idea fails or slows down>
- Test knob: <parameter or construction lever>
- Small shape: <oracle-backed minimal case>
- Scale-up: <how to push toward constraints>
- Validity warning: <optional statement/validator pitfall>
```

## When Adding A New Topic File

- Add the new topic file under `failure-modes/`.
- Add a one-line route in `failure-modes/INDEX.md`.
- Keep the file focused on a mechanism family, not a contest genre.
- Run `checklists/retrieval-audit.md` to confirm the new route improves precision.

## Quality Bar

The entry should help a future session design a testcase. If it only says "remember this bug happened," do not add it.
