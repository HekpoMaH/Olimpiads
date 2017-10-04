@del *.out
@del *.inp
@copy %1.in%2 %1.inp
@showtime
@%1
@showtime
@rem pause
type %1.out
type %1.ou%2
@rem checker %1.inp %1.ou%2 %1.out
