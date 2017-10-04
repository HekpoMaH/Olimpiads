#!/bin/bash

if [ "$1" == "" ] ; then
  echo Usage: check_sol.sh "your solution (executable file)"
  exit
fi

echo Test solution $*

prob=planes
num=0
all=0

for i in `ls ?? ???` ; do
  let all=$all+1
  echo Test $i
  cp $i $prob.in
  if ! (time ./$*) ; then
    echo Runtime Error
    break
    continue
  fi
  if (./check $prob.in $prob.out $i.a) ; then
    let num=$num+1
    echo Ok
  else
    echo Wa
#    break
  fi
done

echo $num of $all tests are passed
