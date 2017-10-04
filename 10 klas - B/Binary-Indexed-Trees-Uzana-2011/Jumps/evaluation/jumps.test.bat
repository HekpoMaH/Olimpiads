echo off

g++ showtime.cpp -o showtime.exe

del jumps.exe 
g++ ..\students\HK-B6\jumps.cpp -o jumps.exe

echo ---Test-01---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.01.in 
time <enter.txt >>time.txt
type ..\tests\jumps.01.sol
showtime

echo ---Test-02---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.02.in 
time <enter.txt >>time.txt
type ..\tests\jumps.02.sol
showtime

echo ---Test-03---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.03.in 
time <enter.txt >>time.txt
type ..\tests\jumps.03.sol
showtime

echo ---Test-04---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.04.in 
time <enter.txt >>time.txt
type ..\tests\jumps.04.sol
showtime

echo ---Test-05---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.05.in 
time <enter.txt >>time.txt
type ..\tests\jumps.05.sol
showtime

pause

echo ---Test-06---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.06.in 
time <enter.txt >>time.txt
type ..\tests\jumps.06.sol
showtime

echo ---Test-07---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.07.in 
time <enter.txt >>time.txt
type ..\tests\jumps.07.sol
showtime

echo ---Test-08---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.08.in 
time <enter.txt >>time.txt
type ..\tests\jumps.08.sol
showtime

echo ---Test-09---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.09.in 
time <enter.txt >>time.txt
type ..\tests\jumps.09.sol
showtime

echo ---Test-10---
time <enter.txt >time.txt
jumps.exe <..\tests\jumps.10.in 
time <enter.txt >>time.txt
type ..\tests\jumps.10.sol
showtime


pause

del jumps.exe
del time.txt
del showtime.exe