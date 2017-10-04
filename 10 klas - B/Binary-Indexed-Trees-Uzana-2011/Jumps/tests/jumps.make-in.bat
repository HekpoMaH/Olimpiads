@echo off

g++ jumps.generator.cpp -o jumps.generator.exe
jumps.generator.exe 
del jumps.generator.exe