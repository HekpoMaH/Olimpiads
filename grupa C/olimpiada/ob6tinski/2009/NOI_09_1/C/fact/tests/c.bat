@echo off
fact < fact.%1.in > fact.out
int.checker 1 fact.out fact.%1.sol

