@echo off

echo Generating jumps.*.in files
call jumps.make-in.bat

echo Generating jumps.*.sol files
call jumps.make-sol.bat 

pause
