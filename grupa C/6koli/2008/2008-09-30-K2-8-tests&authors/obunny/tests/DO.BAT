@echo off


echo --------- Test %1 %2 --------------


obunny<input0%1.txt>obunny.out 
@rem pause2
fc obunny.out answer0%1.txt



