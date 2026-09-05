# Package Inspection Checklist

- Identify platform evidence: Polygon files, CMS files, graders, interactors, scorer code, statements, tests.
- Classify task type: batch, library/sample-grader, interactive, communication, output-only, custom-scored.
- Inventory source files before moving or rewriting anything.
- Classify every solution by evidence: model, brute, subtask, partial, wrong, slow, stub, unknown.
- Locate validators, checkers, interactors, graders, generators, scripts, tests, and scorer files.
- For CMS/local library packages, classify `task.cpp` as contestant-owned stub/template unless evidence says otherwise.
- Determine test naming style and whether renaming is required.
- Identify trusted oracle path for expected outputs.
- Record missing components and uncertainties.
