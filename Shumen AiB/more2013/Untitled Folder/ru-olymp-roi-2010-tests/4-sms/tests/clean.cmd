@echo off
for %%i in (*.exe *.~dpr *.dof *.dsk *.cfg *.in *.out *.a *.obj ?? *.class *.log *.desc) do del %%i

for %%i in (..) do set problem_name=%%~ni
for %%i in (..\%problem_name%_*.*) do del %%~nxi
del ..\check.exe
