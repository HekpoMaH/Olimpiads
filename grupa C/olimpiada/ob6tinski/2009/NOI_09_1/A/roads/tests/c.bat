@echo off
roads < roads.%1.in > roads.out
int.checker 1 roads.out roads.%1.sol

