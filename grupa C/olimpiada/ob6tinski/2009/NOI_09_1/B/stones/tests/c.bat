@echo off
stones < stones.%1.in > stones.out
str.checker 1 stones.out stones.%1.sol

