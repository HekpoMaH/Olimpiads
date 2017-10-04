@echo off
maxk < maxk.%1.in > maxk.out
int.checker 1 maxk.out maxk.%1.sol

