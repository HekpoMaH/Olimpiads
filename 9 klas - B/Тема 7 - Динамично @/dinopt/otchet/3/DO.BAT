@echo off


echo --------- Test %1 %2 --------------


otchet<input0%1.txt>otchet.out 
@rem pause2
fc otchet.out answer0%1.txt



