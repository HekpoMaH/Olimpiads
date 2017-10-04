@echo on
@echo *************************************************
@echo Testov primer %1
@echo Programata izvejda:
@%2 < %2.in%1
@echo Vernia rezultat e:
@type %2.ou%1
@echo off
pause