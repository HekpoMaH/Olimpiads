@echo off
%1.exe < %1.%2.in > %1.out
int.checker 1 %1.out %1.%2.sol
