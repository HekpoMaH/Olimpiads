@echo off
color.exe < color.%1.in > color.out
int.checker 1 color.out color.%1.sol

