rem @echo off
echo Test # %1
echo COMPETITOR:
dots < tests\dots.%1.in
echo AUTHOR:
type tests\dots.%1.sol
echo.
pause
