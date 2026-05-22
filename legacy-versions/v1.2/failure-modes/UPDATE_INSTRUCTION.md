# Failure-Mode Library Update Instructions

Use this folder to preserve transferable testcase-generation knowledge from real investigations. Add lessons here when a wrong solution, slow solution, invalid countertest, benchmark mistake, or verification failure reveals a reusable attack pattern.

## Update Rules

- Choose the closest topic file. If no topic fits, add a focused new topic file and update `INDEX.md`.
- Keep entries transferable. Do not paste task-specific logs, long proofs, or one-off file inventories.
- Record the observed wrong assumption and the corrected guardrail.
- Include both a small counterexample shape and a scalable stress shape when both exist.
- State validation guardrails, especially statement constraints that validators or public graders might miss.
- Preserve invalidated lessons by explaining what made the old attempt invalid and what future agents should check instead.
- Prefer concise patterns over encyclopedic coverage. A future agent should be able to scan a file quickly and choose attack ideas.

## Entry Format

```md
## Failure Mode: <name>

- Wrong assumption:
- Code/editorial smell:
- Small counterexample shape:
- Scalable stress shape:
- Validation guardrails:
- Related files:
```

## When Adding A New Topic File

- Use a lowercase hyphenated filename, such as `shortest-path.md` or `string.md`.
- Add a one-line description to `INDEX.md`.
- Keep topic files independent. Do not require agents to load another topic file to understand an entry.
- If a lesson spans multiple topics, put the main entry in the most specific file and add a short cross-reference elsewhere.

## Quality Bar

- The entry should help construct or validate tests, not merely describe an algorithm.
- The entry should say how the failure becomes visible: WA, TLE, MLE, RE, local-only artifact, or stress-only evidence.
- The entry should distinguish official counterexamples from local artifacts and invalid tests.
- If empirical evidence is involved, require direct-redirection benchmarking and statement-level validation before promotion.
