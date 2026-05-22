# Competitive Programming Task Preparation Skill

AI-assisted workflow for preparing competitive-programming tasks and packages.

Main focus:

* Polygon + CMS + local package preparation
* testcase-generation methodology
* wrong-solution-driven adversarial testing
* benchmark/verification workflows
* iterative refinement through session analysis

The workflow is designed around reusable operational methodology rather than one-off prompts.

---

# Usage

Typical workflow:

1. Load the main skill
2. Optionally load `SKILL_DELTA.md`
3. Run a task-preparation session
4. Verify outputs carefully
5. Generate post-session analysis
6. Batch refinements later

`INSTRUCTIONS.txt` contains an example full-session prompt.

---

# Important Notes

Current CMS support is mainly tested for:

* batch tasks
* grader/header-style tasks
* validators/checkers/generators
* scorer metadata

It is NOT yet well-tested for:

* communication tasks
* OO managers/stubs
* advanced interactive CMS infrastructure

The AI may still produce:

* incorrect solutions
* weak tests
* incomplete verification
* broken generators/scripts
* inconsistent package structures
* or generally unsatisfactory outputs

Always verify outputs manually.

---

# Important Files

* `cp-task-preparation/`

  * main skill folder

* `SKILL_DELTA.md`

  * corrective overlay for recurring model failures

* `INSTRUCTIONS.txt`

  * example task-generation prompt

* `post-analysis.txt`

  * post-session analysis/refinement prompt

* `skill-delta-creation.txt`

  * workflow for extending `SKILL_DELTA.md`

---

## How To Improve The Skill

1. Run real task-preparation sessions.

2. After the session, use `post-analysis.txt` to generate:

* `SESSION_SUMMARY.md`
* `SKILL_CORRECTIONS.md`

3. For lightweight recurring fixes, update `SKILL_DELTA.md` using:

* `skill-delta-creation.txt`

4. For major changes or batched corrections, modify the main skill itself. The skill already contains some guidelines/infrastructure for skill modification and refinement workflows.

5. Prefer batched refinement over constant small mutations.

6. Always manually verify outputs.

---

# Ending Notes

If you use/improve the workflow, I'd appreciate receiving:

* `SESSION_SUMMARY.md`
* `SKILL_CORRECTIONS.md`

so they can be batched into future refinements.
