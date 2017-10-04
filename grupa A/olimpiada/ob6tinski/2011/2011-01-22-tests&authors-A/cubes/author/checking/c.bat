@echo off
cubes < tests\cubes.%1.in > cubes.out
cubes.checker tests\cubes.%1.in cubes.out tests\cubes.%1.sol
