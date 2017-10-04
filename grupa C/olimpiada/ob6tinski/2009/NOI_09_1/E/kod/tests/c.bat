@echo off
kod < kod.%1.in > kod.out
str.checker 1 kod.out kod.%1.sol

