del %1.exe
copy a:\%1.exe

if %2 == 0 goto 0
if %2 == 1 goto 1
if %2 == 2 goto 2
if %2 == 3 goto 3
if %2 == 4 goto 4
if %2 == 5 goto 5
if %2 == 6 goto 6
if %2 == 7 goto 7
if %2 == 8 goto 8
if %2 == 9 goto 9

:0
call do %1 0
pause
:1
call do %1 1
pause
:2
call do %1 2
pause
:3
call do %1 3
pause
:4
call do %1 4
pause
:5
call do %1 5
pause
:6
call do %1 6
pause
:7
call do %1 7
pause
:8
call do %1 8
pause
:9
call do %1 9
pause
