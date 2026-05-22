# Scorer Review Checklist

- Confirm whether scoring is exact, grouped, partial, or custom.
- Confirm whether `scorer.txt` is authoritative or only a summary.
- Confirm whether `scorer.cpp`, checker code, or grader protocol changes the real score.
- Check that point totals add up as intended.
- Check subtask dependencies and included previous groups.
- Check test patterns match the final naming convention.
- For CMS, check `scorer.txt` is exactly an array of `[POINTS, "001|002"]` entries with overlaps preserved and no prose/comments/regex parentheses.
- Document fractional per-test behavior when present.
- Do not invent scoring rules from missing metadata.
