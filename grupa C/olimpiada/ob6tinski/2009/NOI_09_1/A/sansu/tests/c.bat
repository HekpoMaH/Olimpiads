@echo off
sansu < sansu.%1.in > sansu.out
sansu.checker sansu.%1.in sansu.out dummy

