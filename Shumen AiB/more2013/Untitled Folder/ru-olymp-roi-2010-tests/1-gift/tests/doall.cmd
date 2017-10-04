@echo off

call g++ -O2 ../gift_ab_cpp.cpp -o gift_ab_cpp.exe
call g++ -O2 gen.cpp -o gen.exe 

gen.exe

del gen.exe > nul 2> nul
del gen.obj > nul 2> nul

for %%i in (??) do (
  copy %%i gift.in > nul 2> nul 
  gift_ab_cpp.exe
  move gift.out %%i.a > nul 2> nul
  del gift.in > nul 2> nul
)
del gift_ab_cpp.* > nul 2> nul

