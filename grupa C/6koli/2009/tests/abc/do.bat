@echo on
@echo *************************************************
@echo Testov primer %1
@echo Programata izvejda:
@%2 < %2.0%1.in
@echo Vernia rezultat e:
@type %2.0%1.sol
%2 <%2.0%1.in >abc.user.sol
@echo ima li suvpadenie vuv file compare
fc %2.0%1.sol abc.user.sol
@echo off
pause