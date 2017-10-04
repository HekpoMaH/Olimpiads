@echo off




echo --------- Test %1 %2 --------------


%1<test%2.inp>test.out
@fc test%2.out test.out



