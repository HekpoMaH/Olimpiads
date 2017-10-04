@echo off
echo Test %2
prog <%1.%2.in >xxx.out
checker %1.%2.in xxx.out %1.%2.sol
del xxx.out
PAUSE

