#!/usr/bin/env python3
"""Starter statement-level input scanner.

Customize parse_case() for the task. Keep this separate from the official
validator when auditing constraints that the validator might miss.
"""

from pathlib import Path
import sys


def fail(message: str) -> None:
    print(f"Invalid: {message}", file=sys.stderr)
    raise SystemExit(1)


def parse_case(tokens: list[str]) -> dict[str, int]:
    """Replace this parser with the task input format.

    This default matches a common tree-query format:
      N Q
      N-1 edges
      N gem lines: S_i colors...
      Q query pairs
    """
    p = 0
    if len(tokens) < 2:
        fail("missing N Q")
    n = int(tokens[p])
    q = int(tokens[p + 1])
    p += 2
    if n < 1:
        fail("N must be positive")
    p += 2 * (n - 1)

    total_items = 0
    min_s = 10**18
    zero_s = 0
    for i in range(n):
        if p >= len(tokens):
            fail(f"missing S_i at node {i}")
        s = int(tokens[p])
        p += 1
        if s < 1:
            zero_s += 1
        min_s = min(min_s, s)
        total_items += s
        p += s

    p += 2 * q
    if p != len(tokens):
        fail(f"extra or missing tokens: consumed={p} total={len(tokens)}")
    return {"N": n, "Q": q, "total_items": total_items, "min_s": min_s, "zero_s": zero_s}


def main() -> None:
    if len(sys.argv) != 2:
        fail("usage: statement_scan.py case.in")
    path = Path(sys.argv[1])
    result = parse_case(path.read_text().split())
    if result["zero_s"] != 0:
        fail(f"found {result['zero_s']} entries with S_i < 1")
    print("Statement scan valid")
    for key, value in result.items():
        print(f"{key}={value}")


if __name__ == "__main__":
    main()
