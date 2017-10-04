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

function doPatch
{
  echo patching $1 with $2
  ./merge ../tests/$1 pattern.$2 > test.tmp
  mv test.tmp ../tests/$1
}

testdir="../tests"
programs="split gen_rand gen_yes gen_ladder merge"
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

echo "Split small tests"
./split < tests.!!!
for i in `ls *.tmp` ; do
  nextTest "cat $i"
done
rm *.tmp

echo "Random tests"

nextTest "./gen_rand 23925 50 50 1 25"
nextTest "./gen_yes  23926 50 50 2 25"


nextTest "./gen_yes  23928 60 30 2 32"
nextTest "./gen_yes  23930 80 45 3 42"
nextTest "./gen_yes  23930 90 40 3 42"
nextTest "./gen_yes  23930 5 3 3 3"
nextTest "./gen_yes  23932 90 60 1 30"

nextTest "./gen_yes  23934 400 350 2 50"
nextTest "./gen_yes  23936 900 700 3 50"
nextTest "./gen_yes  23938 1000 1000 1 300"
nextTest "./gen_yes  23942 900 666 3 339"
nextTest "./gen_rand 23943 1000 1000 5 500"


nextTest "./gen_yes  23947 400 200 2 270"
nextTest "./gen_yes  23948 50 20 3 50"
nextTest "./gen_yes  23959 70 70 2 35"
nextTest "./gen_yes  23960 90 70 3 35"
nextTest "./gen_yes  23945 200 100 2 78"

nextTest "./gen_yes  23946 300 100 3 120"
nextTest "./gen_yes  23949 1000 500 2 500"
nextTest "./gen_rand 23943 3000 3000 3 1500"
nextTest "./gen_rand 23943 1000 1000 2 600"
nextTest "./gen_rand 23944 1000 1000 1000 1000"


nextTest "./gen_yes  23949 4000 1200 2 1000"
nextTest "./gen_yes  23949 5000 600 3 1300"
nextTest "./gen_yes  23950 8000 800 3 1800"
nextTest "./gen_yes  23950 22000 11000 2 12000"
nextTest "./gen_yes  23950 25000 2400 4 9000"

nextTest "./gen_yes  23950 29000 3200 3 1"
nextTest "./gen_yes  23961 30000 10000 2 5000"
nextTest "./gen_yes  23962 40000 10000 3 11000"
nextTest "./gen_yes  23951 50000 25000 2 12500"
nextTest "./gen_yes  23952 50000 25000 3 25000"


nextTest "./gen_yes  23953 70000 35000 2 35000"
nextTest "./gen_yes  23954 7000 3500 3 4500"
nextTest "./gen_yes  23966 8000 7000 3 3500"
nextTest "./gen_yes  23955 9000 4000 2 4000"
nextTest "./gen_yes  23956 9000 4000 3 4000"

nextTest "./gen_yes  23957 10000 5000 2 5000"
nextTest "./gen_yes  23958 10 5 3 5"
nextTest "./gen_yes  23967 10 3 2 5"
nextTest "./gen_yes  23968 100000 100000 3 50000"
nextTest "./gen_yes  23969 100000 100000 100000 50000"

for f in 11 16 25 ; do
  doPatch $f "01"
done
for f in 08 31 37 ; do
  doPatch $f "02"
done
for f in 12 13 14 17 19 24 26 28 32 36 38 ; do
  doPatch $f "03"
done
for f in 15 18 ; do
  doPatch $f "04"
done

echo "Cleaning up"
for prog in $programs ; do
  rm $prog $prog.exe 2>/dev/null
done

rm $prob.{in,out}
