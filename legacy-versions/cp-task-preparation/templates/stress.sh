#!/usr/bin/env bash
set -euo pipefail

CXX="${CXX:-g++}"
CXXFLAGS="${CXXFLAGS:--std=c++17 -O2 -pipe}"

"$CXX" $CXXFLAGS -o model model.cpp
"$CXX" $CXXFLAGS -o brute brute.cpp
"$CXX" $CXXFLAGS -o gen_random gen_random.cpp

for seed in $(seq 1 1000); do
  ./gen_random "$seed" > input.txt
  ./model < input.txt > model.out
  ./brute < input.txt > brute.out
  if ! diff -u model.out brute.out; then
    echo "Mismatch on seed $seed"
    exit 1
  fi
done

echo "Stress passed"
