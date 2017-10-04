@rem %1 - problem's number (name)
@rem %2 - competitor's number 
@rem %3 - test number
@
@del out
if not exist .\%1.exe goto e
@tmark
@.\%1 < %1.%3.in > out
@tmark
:e
type out
type %1.%3.sol
@eq_line %1.%3.sol out %2 >> res_%1.txt
@echo.
@pause
