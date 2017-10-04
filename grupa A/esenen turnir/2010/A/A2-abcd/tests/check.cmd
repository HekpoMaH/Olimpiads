rem @echo off
for /L  %%i in (1,1,9) Do call ch %1.0%%i.in %1.0%%i.sol
for /L  %%i in (10,1,30) Do call ch %1.%%i.in %1.%%i.sol
rem for %%f in (*.in) Do call ch %%f
echo Done.
