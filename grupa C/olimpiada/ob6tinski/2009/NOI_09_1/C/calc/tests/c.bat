@echo off
calc < calc.%1.in > calc.out
str.checker 1 calc.out calc.%1.sol

