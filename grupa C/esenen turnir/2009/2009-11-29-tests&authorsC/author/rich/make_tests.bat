@echo off
del richmensgames*.in
del richmensgames*.sol
echo Now make IN files. Please, wait... (~30 sec)
"richmensgames-gen.exe"
echo Now make SOL files. Please, wait... (~20 sec)
for %%i in (000 001 002 003 004 005 006 007 008 009 010) do richmensgames<richmensgames.%%i.in>richmensgames.%%i.sol
echo Done!
