@echo off
for %%i in (00 01 02 03 04 05 06 07 08 09 10) do cubes < tests\cubes.%%i.in > tests\cubes.%%i.sol
echo Ready.