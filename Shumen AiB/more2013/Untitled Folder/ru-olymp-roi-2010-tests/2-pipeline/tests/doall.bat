del ?? ??.a

for %%i in (*.cpp) do (
	g++ %%i -o %%~ni.exe
)

copy ??.t ??
gen_rand_nk.exe 50 120 3 123456 > 06
gen_rand_nk.exe 70 200 4 5678 > 07
gen_rand_nk.exe 100 220 3 4324 > 08
gen_rand_nk.exe 40 100 5 9079 > 09
gen_rand_nk.exe 80 250 4 1918 > 10

gen_spec.exe 40 6 0 2432342 > 11
gen_rand_nk.exe 30 180 8 5355672 > 12
gen_greedy.exe 8 3 645532 > 13
gen_spec 24 3 1 543534 > 14
gen_spec 28 2 1 874664 > 15

gen_2k.exe 50 10 1 9 5345435 > 16
gen_2k.exe 40 9 1 9 89756 > 17
gen_2k.exe 40 9 1 9 53455 > 18

gen_2k.exe 60 10 2 9 898567 > 19
gen_2k.exe 100 9 70 100 5345 > 20

gen_2k.exe 45 10 1 9 35345 > 21
gen_2k.exe 42 9 1 9 482368345 > 22
gen_2k.exe 41 9 1 9 823234 > 23
gen_2k.exe 49 10 1 9 901852 > 24
gen_2k.exe 52 10 1 9 94305 > 25

gen_2k.exe 44 9 1 9 58696 > 26
gen_2k.exe 42 9 1 9 9009523 > 27
gen_2k.exe 51 10 1 9 78636 > 28
gen_2k.exe 51 10 1 9 70005 > 29
gen_2k.exe 41 9 1 9 435535 > 30


javac TestGen.java
java TestGen > comments2.txt
