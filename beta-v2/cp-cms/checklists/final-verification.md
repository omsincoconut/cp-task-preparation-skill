# CMS Final Verification Checklist

- Target CMS task type and loader/repository convention are explicit.
- File roles are not conflated (manager, stub, grader, checker, validator, contestant template).
- Public headers/stubs compile with delivered contestant templates where applicable.
- Admin manager/grader/checker/validator sources compile in the intended environment as far as locally testable.
- Test Plan logical cases/groups are mapped completely or unresolved gaps are reported.
- Every testcase satisfies the intended validity restrictions.
- Trusted full oracle path is identified before generating ordinary expected outputs.
- Scoring preserves per-test outcome vs score aggregation semantics.
- Communication tasks pass `checklists/communication-verification.md`.
- Repository-specific filenames/layout are preserved unless normalization was requested.
- CMS-worker/importer assumptions that cannot be verified locally are stated explicitly.
