# Skill Application Checklist

- Start by reading `SKILL.md` and this checklist.
- Load only the references needed for the current task type and platform.
- For existing packages, inspect before editing.
- Separate convention evidence from testcase-generation evidence.
- Before promoting generated tests, run `checklists/statement-validator-audit.md`.
- Before reporting runtime or memory behavior, run `checklists/benchmark-harness.md`.
- Before calling a testcase a counterexample, run `checklists/countertest-promotion.md`.
- For in-session or post-session skill updates, use `references/refinement-workflow.md`.
- During active task sessions, fix or stabilize the current package first, then use the refinement workflow for reusable skill changes.
- Choose templates only after confirming the component is needed.
- Apply platform-specific naming: Polygon `01`/`01.a`, CMS `001.in`/`001.out`.
- Ask or document uncertainty instead of filling gaps by imitation.
- Before final delivery, run `checklists/final-verification.md`.
