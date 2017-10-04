@echo off
fatal < fatal.%1.in > fatal.out
int.checker 1 fatal.out fatal.%1.sol

