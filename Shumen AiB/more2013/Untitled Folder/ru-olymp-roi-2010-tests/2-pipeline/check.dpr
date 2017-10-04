uses
	testlib, SysUtils;
const
	MAXN = 1000;
var
	n, m, k, i, x, y: integer;
	ansj, ansp: string;
	u : array[1..MAXN] of boolean;
begin
	n := inf.readlongint;
	m := inf.readlongint;
	k := inf.readlongint;
	ansp := uppercase(ouf.readstring);
	ansj := uppercase(ans.readstring);
	if (ansp <> 'NO') and (ansp <> 'YES') then begin
		quit(_wa, '����������� ������ Yes ��� No.');
	end;
	if (ansp = 'NO') then begin
		if (ansj = 'NO') then begin
			quit(_ok, '��� �������.');
		end
		else begin
			quit(_wa, '������� �� �������.');
		end;
	end;
	fillchar(u, sizeof(u), 0);
	for i := 1 to k do begin
		x := ouf.readlongint;
		if (x < 1) or (x > n) then begin
			quit(_wa, '������ ����� ' + intToStr(i) + ' ��� ����������� ���������.');
		end;
		if (u[x]) then begin
			quit(_wa, '�� ������� ' + intToStr(x) + '������������ ����� ������ �������.');
		end;
		u[x] := true;
	end;
	for i := 1 to m do begin
		x := inf.readlongint;                                     
		y := inf.readlongint;                                     
		if (not u[x]) and (not u[y]) then begin
			quit(_wa, '����������� ����� ' + intToStr(i) + ' (' + intToStr(x) + ', ' + intToStr(y) + ')  �� ��������������.');
		end;
	end;
	if (ansj = 'NO') then begin
		quit(_fail, '�������� ����� �������?!');
	end;
	quit(_ok, intToStr(k) + ' ������.');
end.
