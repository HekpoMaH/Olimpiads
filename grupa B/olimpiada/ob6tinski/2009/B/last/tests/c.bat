@echo off
last < last.%1.in > last.out
int.checker 1 last.out last.%1.sol

