gpp -o egypt.exe egypt.cpp
gpp -o egypt_checker.exe egypt_checker.cpp

rem===================================

del egypt.ou0
egypt < egypt.in0 > egypt.ou0
egypt_checker egypt.in0 egypt.ou0 >> res

del egypt.ou1
egypt < egypt.in1 > egypt.ou1
egypt_checker egypt.in1 egypt.ou1 >> res

del egypt.ou2
egypt < egypt.in2 > egypt.ou2
egypt_checker egypt.in2 egypt.ou2 >> res

del egypt.ou3
egypt < egypt.in3 > egypt.ou3
egypt_checker egypt.in3 egypt.ou3 >> res

del egypt.ou4
egypt < egypt.in4 > egypt.ou4
egypt_checker egypt.in4 egypt.ou4 >> res

del egypt.ou5
egypt < egypt.in5 > egypt.ou5
egypt_checker egypt.in5 egypt.ou5 >> res

del egypt.ou6
egypt < egypt.in6 > egypt.ou6
egypt_checker egypt.in6 egypt.ou6 >> res

del egypt.ou7
egypt < egypt.in7 > egypt.ou7
egypt_checker egypt.in7 egypt.ou7 >> res

del egypt.ou8
egypt < egypt.in8 > egypt.ou8
egypt_checker egypt.in8 egypt.ou8 >> res

del egypt.ou9
egypt < egypt.in9 > egypt.ou9
egypt_checker egypt.in9 egypt.ou9 >> res

echo >> res

type res
