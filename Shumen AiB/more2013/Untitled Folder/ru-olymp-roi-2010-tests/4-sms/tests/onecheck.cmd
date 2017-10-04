@echo off
if "%1" == "" (
  echo No parameters found
    exit       
)

for %%i in (..) do (
    set problem_name=%%~ni
)

if "%2" == "" (
    echo No second parameter found
    exit
) else (
    echo Running on test: %2
    copy %2 %problem_name%.in > nul
    if EXIST %problem_name%_%1.exe run -t 5 %problem_name%_%1.exe
    if EXIST %problem_name%_%1.class run -t 5 java -Xss64M -Xmx256M %problem_name%_%1
    if EXIST %problem_name%_%1.py run -t 5 python %problem_name%_%1.py
    check %problem_name%.in %problem_name%.out %2.a

    if errorlevel 1 (
      echo %2 failed >> docheck_%problem_name%_%1.log 
    ) else (
        echo %2 ok >> docheck_%problem_name%_%1.log 
    )
)