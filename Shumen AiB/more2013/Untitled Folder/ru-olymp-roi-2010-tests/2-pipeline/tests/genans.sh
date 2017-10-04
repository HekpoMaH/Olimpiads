#!/bin/bash

sol=../pipeline_vg_100
prob=pipeline

echo "Compile solution"

g++ -O2 -Wall $sol.cpp -o x

for i in `ls ??` ; do
  echo "Test $i"
  cp $i $prob.in
  time ./x 
  cp $prob.out $i.a
done

rm x
rm x.exe
rm $prob.{in,out}
