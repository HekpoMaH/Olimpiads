@echo off
if "%1" == "" (
  echo No parameters found
    exit       
)

for %%i in (..) do (
    set problem_name=%%~ni
)

call dcc32 -cc ..\check.dpr
copy ..\check.exe check.exe

copy ..\%problem_name%_%1.* .\*
if EXIST %problem_name%_%1.dpr dcc32 -cc %problem_name%_%1.dpr
if EXIST %problem_name%_%1.cpp g++ -O2 %problem_name%_%1.cpp -o %problem_name%_%1.exe
if EXIST %problem_name%_%1.java javac %problem_name%_%1.java

:compiled


if "%2" == "" (
  echo %date% %time% > docheck_%problem_name%_%1.log     
    for %%i in (??) do (        
        call onecheck %1 %%i
    )
) else (
    call onecheck %1 %2
)