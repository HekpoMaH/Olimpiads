var e:array[1..2000,1..3] of integer;
    i, j, k, m, n, x, y: integer;
    l: boolean;
begin
  k:=0;
  for i:=1 to 20 do for j:=1 to 3 do e[i,j]:=0;
  readln(n);
  for i:=1 to n do begin
    readln(x,y);
    j:=1;
    while (j<=k) and (e[j,1]<>x) do j:=j+1;
    if j>k then begin k:=k+1; e[k,1]:=x; e[k,3]:=1 end
           else e[j,3]:=e[j,3]+1;
    j:=1;
    while (j<=k) and (e[j,1]<>y) do j:=j+1;
    if j>k then begin k:=k+1; e[k,1]:=y; e[k,2]:=1 end
           else e[j,2]:=e[j,2]+1;
  end;
  j:=0;
  for i:=1 to k do
    if e[i,2]=0 then begin j:=j+1; m:=i end;
  if j<>1 then begin writeln('0 0'); exit end;
  l:=true;
  for i:=1 to k do if i<> m then l:=l and (e[i,2]=1);
  if not l then begin writeln('0 0'); exit end;
  writeln(k,' ',e[m,1]);
end.