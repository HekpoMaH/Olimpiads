#!/bin/bash

if [ "$1" == "" ] || [ "$2" == "" ]  ; then
  echo Usage: stress.sh "<sol1>" "<sol2>" "<generator and its arguments>"
  exit
fi

sol1=$1
sol2=$2

shift
shift

echo Stress solutions $sol1 and $sol2
echo Generator = $*

num=0
prob=rectangle

for (( ; ; )) ; do
  ./$* > $prob.in
  time ./$sol1
  cp $prob.out $prob.ans
  time ./$sol2
  if !(./check $prob.in $prob.out $prob.ans) ; then
    echo Fail!
    echo $num tests were passed
    exit
  fi
  let num=$num+1
  echo num = $num
done
