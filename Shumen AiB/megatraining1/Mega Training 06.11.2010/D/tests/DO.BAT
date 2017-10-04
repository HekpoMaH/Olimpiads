@echo off

del %1.inp > nul
del %1.out > nul

copy %1.in%2 %1.inp

echo --------- Test %1 %2 --------------


%1< %1.inp>%1.out
@rem pause2
fc %1.out %1.ou%2



