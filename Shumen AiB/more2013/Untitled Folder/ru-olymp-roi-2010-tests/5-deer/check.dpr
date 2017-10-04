uses
	testlib, SysUtils;

const EPS = 2e-3;

var
	jans, pans: extended;
	n: longint;
begin
	jans := ans.readreal;
	pans := ouf.readreal;
	n := inf.readlongint;
	if (abs(jans - pans) > EPS) then quit(_wa, 'ќжидалось: ' + floatToStr(jans) + ', получено: ' + floatToStr(pans));
	quit(_ok, intToStr(n) + ' вершин, площадь равна ' + floatToStr(pans));
end.
