@echo off

for %%i in (*.t) do (
  copy %%i %%~ni > nul
)

call javac TestsGen.java
call java TestsGen
del TestsGen.class

dcc32 -cc ..\check.dpr

call tall ab_mitm
call docheck sp_rmqbins
