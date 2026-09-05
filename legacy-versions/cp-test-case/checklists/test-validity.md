# Test Validity Checklist

- Extract every input and semantic constraint used by the testcase plan.
- Reconcile statement limits with any trusted validator/manager/parser evidence.
- Check global sum constraints and subtask promises, not only per-field ranges.
- Check structural invariants independently for adversarial and max-size cases.
- Reject or regenerate any promoted case that violates the statement-level validity model.
- Invalidate benchmark conclusions obtained from illegal inputs.
- Put unresolved validity conflicts in the Test Plan residual-risk section.
