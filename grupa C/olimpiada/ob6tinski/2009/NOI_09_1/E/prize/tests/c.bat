@echo off
prize < prize.%1.in > prize.out
str.checker 1 prize.out prize.%1.sol

