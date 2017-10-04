@echo off
princess < princess.%1.in > princess.out
int.checker 2 princess.out princess.%1.sol

