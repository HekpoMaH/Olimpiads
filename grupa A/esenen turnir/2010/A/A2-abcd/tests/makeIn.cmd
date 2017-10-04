@echo off
for /L  %%i in (1,1,9) Do copy %1.00.in %1.0%%i.in
for /L  %%i in (10,1,30) Do copy %1.00.in %1.%%i.in

