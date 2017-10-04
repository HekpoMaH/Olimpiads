@echo off

g++ ..\author\jumps.author-2.cpp -o jumps.author.exe

echo jumps.01.sol
jumps.author.exe <jumps.01.in >jumps.01.sol
echo jumps.02.sol
jumps.author.exe <jumps.02.in >jumps.02.sol
echo jumps.03.sol
jumps.author.exe <jumps.03.in >jumps.03.sol
echo jumps.04.sol
jumps.author.exe <jumps.04.in >jumps.04.sol
echo jumps.05.sol
jumps.author.exe <jumps.05.in >jumps.05.sol
echo jumps.06.sol
jumps.author.exe <jumps.06.in >jumps.06.sol
echo jumps.07.sol
jumps.author.exe <jumps.07.in >jumps.07.sol
echo jumps.08.sol
jumps.author.exe <jumps.08.in >jumps.08.sol
echo jumps.09.sol
jumps.author.exe <jumps.09.in >jumps.09.sol
echo jumps.10.sol
jumps.author.exe <jumps.10.in >jumps.10.sol

del jumps.author.exe
