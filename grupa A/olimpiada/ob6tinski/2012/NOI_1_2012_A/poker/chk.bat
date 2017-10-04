@echo off
for /L %%i in (1,1,9) do call c 0%%i
for /L %%i in (10,1,25) do call c %%i
echo Ready.
