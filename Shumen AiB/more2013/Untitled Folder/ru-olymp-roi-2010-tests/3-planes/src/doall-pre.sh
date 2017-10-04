#!/bin/bash

function make
{
  echo "Compile $1"
  g++ -O2 -Wall $1.cpp -o $1
}

function nextTest
{
  ti=`printf "%02d" "$nt"`
  echo "$1 > $ti"
  $1 > ../tests/$ti || exit 1
  let nt=$nt+1
  let base=$base+1
}

testdir="../tests"
programs="split gen_rand gen_yes gen_ladder"
nt=1
prob=planes
base=23917

echo "Clear enviroment"
rm -rf $testdir

mkdir $testdir 2>/dev/null

echo "Compiling programs"
for prog in $programs ; do
  make $prog
done

echo "Generate tests"

echo "Manual tests"
for i in `seq -w 01 03` ; do
  nextTest "cat $i.manual"
done

echo "Split small tests"
./split < tests.!!!
for i in `ls *.tmp` ; do
  nextTest "cat $i"
done
rm *.tmp

echo "Random tests"
n="100 1000 100000"
k="1 2 3"
for i in $n ; do
  for j in $k ; do
    let x=$i/2
    nextTest "./gen_rand $base $i $i $j $x"
    nextTest "./gen_yes $base $i $i $j $x"
  done
done
k=3
n="20000 50000 70000 100000"
for i in $n ; do
  let x=$i/2
  nextTest "./gen_yes $base $i $x $k $x"
done

echo "Cleaning up"
for prog in $programs ; do
  rm $prog $prog.exe 2>/dev/null
done

rm $prob.{in,out}
