#!/usr/bin/env bash
set -euo pipefail

CXX="${CXX:-g++}"
CXXFLAGS="${CXXFLAGS:--std=c++17 -O2 -pipe}"

"$CXX" $CXXFLAGS -o gen_random gen_random.cpp
"$CXX" $CXXFLAGS -o gen_structured gen_structured.cpp
"$CXX" $CXXFLAGS -o model model.cpp

mkdir -p tests

./gen_structured sample > tests/01
./gen_random 10 1 > tests/02

for id in tests/[0-9][0-9]; do
  ./model < "$id" > "$id.a"
done
