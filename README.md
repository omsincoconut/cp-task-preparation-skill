# Competitive Programming Task Preparation Skill

AI workflow for preparing competitive-programming tasks and packages for Polygon and CMS.

---
# Usage

Usage instructions for v1.3

1. Load the skill.
2. In the directory where you will build the package, paste [testlib](https://github.com/MikeMirzayanov/testlib) and other reference files.
3. Call the skill in the directory that you will be building your packages with your task statement and prompts.

Note that v1.3 does not support communication in CMS yet. That support is added in beta-v2.

---

# Important Files

* `cp-task-preparation/`

  * main v1.3 skill folder

* `beta-v2/`

  * beta version. not tested yet.
  * split into three separate skills: cp-polygon, cp-cms, cp-test-case
  * added support for communication problems in cms
  * added instructions on [polyman](https://github.com/HamzaHassanain/polyman) in case you have it installed
  * added testlib.h and other references into the skill files

* `legacy-versions/`

  * legacy versions (v1.1 and v1.2) of the skill
  * v1.1 is much lighter than v1.3

* `SKILL_DELTA.md`

  * corrective overlay for recurring model failures

---

# Notes

I do not own [testlib](https://github.com/MikeMirzayanov/testlib), [polyman](https://github.com/HamzaHassanain/polyman), [codeforces polygon rules](http://codeforces.com/r/authors-polygon-rules), or defs.toml. It is included into the skill file for easier use.
