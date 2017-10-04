@echo off
square < square.%1.in > square.out
int.checker 1 square.out square.%1.sol

