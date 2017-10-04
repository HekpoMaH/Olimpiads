#!/bin/bash

echo "Compile validator"

g++ -O2 -Wall validate.cpp -o x

echo "Validate tests"

for i in `ls ../tests/??` ; do
  echo "[$i]"
  if !(./x < $i) ; then
    echo "Суровая хрень says: Failed :-("
    break
  fi
done

rm -f x x.exe
