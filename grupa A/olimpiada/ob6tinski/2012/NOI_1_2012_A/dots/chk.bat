@echo off
for /L %%i in (1,1,9) do call c 00%%i
for /L %%i in (10,1,30) do call c 0%%i
echo Ready.
