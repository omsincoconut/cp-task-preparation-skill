# Codeforces Round Preparation Rules

Source: [Codeforces authors Polygon rules](http://codeforces.com/r/authors-polygon-rules)

> You **must** follow these rules to prepare a Codeforces Round. For any deviations, talk to your coordinator.

## What's New

| Date | Change |
|---|---|
| July 30, 2025 | Do not reuse the same variable name for a different object in the statement. |
| April 13, 2025 | Footnotes usage. |
| February 23, 2025 | `\Def*` commands now also work for XOR, AND, and OR. |
| December 26, 2024 | Added `\Def*` standard phrases. The Statements section was reformatted. |
| August 24, 2024 | Specify `mex()` and other functions to be spelled lowercase in formulas. |
| May 26, 2024 | Pretests should be equal to tests. The limits on the number of tests have been changed. |
| February 19, 2024 | The validator should use the same variable names as the statement. |
| January 10, 2024 | All problems should have multitests. |

## General

This document is not a Polygon guide, but rather a list of standards and common practices you need to follow to minimize the likelihood of mistakes.

Read the document carefully, even if you have experience preparing problems or have prepared Codeforces rounds before.

If anything is unclear, speak to your coordinator.

## Warnings

Some things are checked automatically. Make sure to check, read carefully, and correct the problem to avoid the following warnings:

- Working copy warnings in Polygon:
  - displayed when you commit changes;
  - displayed on the Review page;
  - highlighted in orange/red on the right.
- Package warnings in Polygon:
  - displayed on package pages;
  - displayed on the contest page as a yellow warning triangle.
- Discord bot warnings:
  - available through the `$check` command in the round server.

## Checker, Validator, and Interactor

- Use `testlib.h`.
- Read the relevant help and look at examples on the respective pages in Polygon.
- Do not use any random source other than `testlib.h`.
- Do not use `#define`s. Write understandable code.
- Do not mix tabs and spaces. Your code on the Review page should be easy to read.
- In validator `read*()` statements, the variable name should be exactly the same as in the statement.

### Validator

- Use array-reading functions like `read*s(n, ...)` instead of loops whenever possible.
- Check the limit on the sum of `n` after each test case.

### Checker

- Use these checkers whenever possible, in this order of priority:
  1. `std::ncmp.cpp`
  2. `std::nyesno.cpp`
  3. `std::wcmp.cpp`
- If the above is not enough, use a standard checker if possible.
- If you have to use a custom checker:
  - use the `readAns` paradigm;
  - the function must be named `readAns`;
  - initialize all global variables at the beginning of the `readAns` function.
- Do not check for whitespace unless you need to.
- Use `readToken()` instead of `readLine()`.
- Do not validate the input file in the checker, including with `inf.readSpace()` or `inf.readEoln()`.
- Always set limits when reading from `ouf` and `ans`.

Checker comments on examples are visible to contestants. Therefore:

- Do not spoil anything in the comments.
- Make the checker's comments easy to understand.

## Tests and Generators

- Use multitests in all problems: `t <= 10^4`.
- Do not use the "add tests from archive/files" feature.
  - Examples should be manual tests.
  - Other tests should be generated.
- The first test after examples, typically the second test overall, should list all possible small tests.
- Start from the smallest possible test case, typically `n = 1`, and generate all possible arrays, graphs, etc.
- Do not use the following syntax in Polygon scripts:

  ```text
  gen > {1-100}
  ```

  Use generators that generate exactly one test on each run.

- Make generator names distinguishable.

  Bad names:

  ```text
  gen1
  gen2
  gen3
  ```

  Bad names when passed as a parameter:

  ```text
  gen type=1
  gen type=2
  gen type=3
  ```

  Good names:

  ```text
  gen_path
  gen_binary
  gen type=random
  ```

- Always make tests with at least:
  - the minimum possible value;
  - the maximum possible value;
  - a middle value;
  - combinations of these values for each variable.
- Do not use a generator with the same parameters, but different seeds, more than once.
- Pretests must be equal to tests.
- For D2A:
  - total input size should be no more than `50'000`;
  - when possible, use `t <= 500` and `n <= 100`.

### Maximum Number of Tests

| Problem | Maximum tests |
|---|---:|
| D2A | 4 |
| D2B | 10 |
| D2C | 20 |
| D2D | 30 |

## Statements

### General

Statements are the face of the problem. They must be correct, understandable, and tidy.

- Do not make long statements. The legend should fit into the initial size of the text area in Polygon.
- Use an AI helper to correct the grammar.
- Use American English.
- All character names should be widespread common names.
- Do not use nicknames or usernames.
- Words in English titles should almost always start with a capital letter.
  - Suggested helper: <https://capitalizemytitle.com>
- Use common phrases and parts to write usual things.
  - If you have already seen a problem with the sentence you need, copy it.
- Many standard phrases are available through special `\Def*` macros.
  - See the list in the `cf-defs` problem in Polygon examples.
- If some items in the table below can be used in your statements, copy them.
- Use footnotes for information you expect experienced participants to know, such as many of the `\Def*` macroses.
- Do not use footnotes when new information is provided, such as a non-standard definition.
- Do not reuse the same variable name for a different object.

Wrong:

```text
An array $a$ is nice if... You are given an array $a$.
```

Correct:

```text
An array $a$ is nice if... You are given an array $b$.
```

### Examples

- Use at least one example for each possible output format.
- Use at least two example test cases per problem.
- It is better to have more examples in easier problems.
- At least two examples should have a note or explanation.
- Add a note for each tricky example that could cause questions.

### Formatting

- Use only lowercase letters for variables: `$n$`, not `$N$`.
  - Exception: sets and graphs.
- Avoid multi-letter variables.
- If multi-letter variables are needed, write them in roman, not italic:

  ```tex
  $\mathrm{dis}_{i, j}$
  ```

- All variables, limits, and large constants should be in TeX formulas.

Wrong:

```text
m does not exceed one hundred.
```

Correct:

```text
$m$ does not exceed $100$.
```

This is fine because the number is not a limit or a large number:

```text
There are three types of cells.
```

- Use italic `\textit{}` to introduce a definition.
- Use bold `\textbf{}` to mark something important.
- Use italic and bold only for a word or several words.
- If you want to bold a sentence or a few sentences, rewrite the statement.
- Write clear text.
- End statements with full stops.
- Start statements with capital letters.
- Place spaces properly.

Wrong:

```text
word1,word2
word1(word2)word3
word1 ( word2 ) word3
```

Correct:

```text
word1, word2
word1 (word2) word3
```

- Formulas are part of the sentence. Place punctuation marks as if the formulas are spelled out.
- Display formulas should usually have a comma or a full stop at the end.

### Input Format

- Make the structure of the text reflect the structure of the input.
- One paragraph should correspond to one line of the input.
- Give constraints on each value in parentheses right after its appearance in the input format.
- Parentheses should not be included in the TeX formula.

Example:

```text
$n$ ($1 \le n \le 10^5$).
```

- List all numbers on a line first, then give constraints.

Wrong:

```text
two integers $n$ ($1 \le n \le 100$) and $m$ ($1 \le m \le 100$).
```

Correct:

```text
two integers $n$ and $m$ ($1 \le n, m \le 100$).
```

- Do not use the phrase "space-separated" unless it is needed.

### TeX Formatting

- Do not include text elements, such as words, spaces, or punctuation marks, inside TeX formulas.

Wrong:

```text
two integers $x, y$ $(1 \le x \le 10, 2 \le y \le 5)$.
```

Correct:

```text
two integers $x$, $y$ ($1 \le x \le 10$, $2 \le y \le 5$).
```

Possible exception: a sequence, list, or array:

```tex
$x_1, x_2, \ldots, x_n$
```

- To denote a sequence, use only its id or list all elements.

Wrong:

```text
a sequence $x_i$.
```

Correct:

```text
a sequence $x$ of length $n$
```

Even better:

```tex
a sequence $x_1, x_2, \ldots, x_n$
```

- For a dash, use `~---`.
  - There should be no space before `~`.
- For indices, use `$i$-th` and similar forms.
  - Russian equivalents: `$i$-й`, `$i$-я`, `$i$-го`.
- Use `\cdot` in formulas for multiplication.
- Use `\bmod` for the modulus operation.

Example:

```tex
In Euclid's algorithm, you repeatedly replace $(a, b)$ with $(b, a \bmod b)$.
```

- Use `\equiv` and `\pmod` to show equivalence modulo some number.

Example:

```tex
$a^{p - 1} \equiv 1 \pmod{p}$ holds for any prime $p$.
```

- Use lowercase function names in formulas, for example:

  ```tex
  $\operatorname{mex}(1, 3, 0, 2, 5)$
  ```

- Use `$s = \mathtt{abacaba}$` to denote string constants in formulas.
- Use `\texttt{abacaba}` outside formulas.
- Do not use quotation marks for string constants.
- Use square brackets to denote sequences and arrays.

Example:

```text
array is $[3, 4, 5, 3]$
```

- Use curly brackets to denote sets and multisets with no general order.

Example:

```text
the good values are $\{3, 4, 7\}$
```

### Standard Statement Phrases

| English | Russian | Notes |
|---|---|---|
| The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$). | Первая строка каждого набора входных данных содержит одно целое число $n$ ($1 \le n \le 10^5$). |  |
| The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$). | Вторая строка содержит $n$ целых чисел $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$). |  |
| Each of the next $m$ lines contains two integers $x$ and $y$ ($1 \le x, y \le n$).<br><br>Or:<br><br>The $i$-th of the next $m$ lines contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$). | Каждая из следующих $m$ строк содержит два целых числа $x$ и $y$ ($1 \le x, y \le n$).<br><br>Или:<br><br>$i$-я из следующих $m$ строк содержит два целых числа $x_i$ и $y_i$ ($1 \le x_i, y_i \le n$). |  |
| You can output the answer in any case (upper or lower). For example, the strings ``\t{yEs}'', ``\t{yes}'', ``\t{Yes}'', and ``\t{YES}'' will be recognized as positive responses. | Вы можете выводить каждую букву в любом регистре (строчную или заглавную). Например, строки <<\t{yEs}>>, <<\t{yes}>>, <<\t{Yes}>> и <<\t{YES}>> будут приняты как положительный ответ. |  |
| If there are multiple solutions, print any of them. | Если существует несколько решений, выведите любое из них. |  |
| If there is no solution, print a single integer $-1$. | Если решения не существует, выведите одно целое число $-1$. |  |
| We can show that an answer always exists. | Можно показать, что ответ всегда существует. | Put this phrase in the legend or output section. It means that for every possible input an answer exists. No additional constraints are added. |
| It is guaranteed that... | Гарантируется, что... | This means that the input is specially prepared so that the condition holds. Put this in the legend and input section. Example: `It is guaranteed that the given edges form a tree.` |
| `example` | `пример` |  |
| `Smth is as follows.` |  | Always singular. |

## Solutions

For each problem, there should be:

- The main correct solution:
  - written without non-asymptotic optimizations;
  - using at most half the time limit and half the memory limit.
- A correct Java solution if Java solutions may work slowly, including but not limited to:
  - C++ solutions using more than `1/4` of the time limit;
  - C++ solutions using more than `50 MB`.
- Other correct solutions:
  - including at least one by another author;
  - all correct solutions should fit within half the time limit and half the memory limit.
- A stupid bruteforce solution:
  - does exactly what is written in the statement;
  - should only receive OK or TL;
  - use `while (true);` if needed;
  - select the tag `Time Limit Exceeded` for it.
- Slow solutions that you do not want to pass:
  - optimize them as much as possible, including with pragmas;
  - they should not fit double the time limit or memory limit.
- Use the tag `Time Limit Exceeded or Correct` only for solutions on the boundary of the time limit.
- For solutions that get TL, use the tag `Time Limit Exceeded`.
- For easy problems, write a solution in Python and make sure it passes without any optimizations.
- Do not use `g++64` in the main correct solution.
- If overflow is possible in the main solution, write a Python solution.
- If incorrect solutions due to overflow are possible:
  - add one for each variable, array, or code location where overflow can occur;
  - make sure they all fail on pretests.
- If possible, do not make tight limits.
- For harder problems, `2` seconds is the minimum possible time limit.
- If there is a solution with casework, or part of the problem requires casework:
  - write such a solution;
  - add a wrong solution for each case commented out;
  - make sure they all fail on pretests.

## Stresses

Each problem should have at least two stress tests on the Stresses tab:

1. One stress on random big tests with correct solutions.
   - Other correct solutions, such as a tester's solution, will be added to it and checked.
2. One stress on random small tests with the bruteforce solution.

Make sure the stress generators can produce all possible tests. For example:

- `n` should not be limited to a fixed value;
- array elements should not be limited to distinct values or values at most `n`;
- the graph should not be limited to connected graphs.

## Editorial

- Editorials should be written in the Statements tab, in the Tutorial field.
- After the round, you can quickly import editorials into a Codeforces blog post using `[tutorial:<round-id><problem-letter]` tags.

Example:

```text
[tutorial:2048A]
```
