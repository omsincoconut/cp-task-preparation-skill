# Testcase Final Verification Checklist

- Statement constraints and validator behavior were reconciled.
- A trusted full oracle path is identified before expected outputs are generated.
- Samples are preserved exactly where required.
- Tiny/exhaustive or hand-checkable cases cover base behavior.
- Boundary and structured cases cover each important variable/shape.
- Each adversarial test has a documented targeted failure mechanism.
- Wrong/partial solutions fail where claimed; accepted/model solutions pass.
- Slow-solution claims are supported by reproducible benchmark evidence under intended limits.
- Random tests add distinct coverage rather than replacing structured cases.
- Max-stress cases remain statement-valid.
- Seeds, generator parameters, commands, and relevant logs are reproducible.
- Test/subtask membership and verdict matrix are documented.
