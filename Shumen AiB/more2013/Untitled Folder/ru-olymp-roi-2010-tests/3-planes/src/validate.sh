#!/bin/bash

echo "Compile validator"

g++ -O2 -Wall validate.cpp -o x

echo "Validate tests"

for i in `ls ../tests/??` ; do
  echo "[$i]"
  if !(./x < $i) ; then
    echo "������� ����� says: Failed :-("
    break
  fi
done

rm x
rm x.exe
rm $prob.{in,out}
