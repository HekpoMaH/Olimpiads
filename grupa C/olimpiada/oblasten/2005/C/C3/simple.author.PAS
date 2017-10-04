var m, x, y: array[1..100] of integer;
    n, p, i, j, mm, mx: integer;
begin
  readln(n, p);
  for i:=1 to p do begin x[i]:=0; y[i]:=0 end;
  for i:=1 to n do begin
    mm:=1001; mx:=0;
    for j:=1 to p do begin
      read(m[j]);
      if m[j]<mm then mm:=m[j];
      if m[j]>mx then mx:=m[j];
    end;
    for j:=1 to p do begin
      if m[j]=mm then x[j]:=x[j]+1;
      if m[j]=mx then y[j]:=y[j]+1;
    end;
    readln;
  end;
  for j:=1 to p do
    if (x[j]>=(n div 2)) and (y[j]=0) then write(j,' ');
  writeln
end.