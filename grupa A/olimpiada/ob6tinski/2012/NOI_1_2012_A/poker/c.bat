@echo off
echo Test # %1
echo COMPETITOR:
poker < tests\poker.%1.in
echo.
echo AUTHOR:
type tests\poker.%1.sol
echo.
pause
