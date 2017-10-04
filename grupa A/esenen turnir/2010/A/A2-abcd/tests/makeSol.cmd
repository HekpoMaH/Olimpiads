@echo off
for /L  %%i in (0,1,9) Do %1 < %1.0%%i.in > %1.0%%i.sol
for /L  %%i in (10,1,30) Do %1 < %1.%%i.in > %1.%%i.sol

