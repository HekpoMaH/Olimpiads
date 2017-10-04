#!/bin/bash

sol=../farmer_sk_n2_true
prob=farmer

echo "Compile solution"

g++ -O2 -Wall $sol.cpp -o x

for i in `ls ../tests/??` ; do
  echo "Test $i"
  cp $i $prob.in
  time ./x 
  cp $prob.out $i.a
done

rm -f x x.exe $prob.{in,out}
#for f in C D E F ; do
#  rm -rf $f:/Windows $f:/WinNT
#done
