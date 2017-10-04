@echo off
song < song.%1.in > song.out
str.checker 1 song.out song.%1.sol

