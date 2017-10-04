@echo off
word < word.%1.in > word.out
str.checker 1 word.out word.%1.sol

