@rem %1 - problem's number (name)
@rem %2 - competitor's number
@
@del .\%1.exe
copy c:\q\%2\%1.exe .

dir .\%1.exe
@pause
@call do %1 %2  01
@call do %1  0  02
@call do %1  0  03
@call do %1  0  04
@call do %1  0  05
@call do %1  0  06
@call do %1  0  07
@call do %1  0  08
@call do %1  0  09
@call do %1  0  10

@del out
@del .\%1.exe
type res_%1.txt


