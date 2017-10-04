@echo on
@echo *************************************************
@echo Testov primer %1
@echo Programata izvejda:
@%2 < %2.0%1.in
@echo Vernia rezultat e:
@type %2.0%1.sol
@echo off
pause