program groups;
var a:array[1..500] of real;
    b:array[1..500] of real;
    c:array[1..500] of real;
    r:array[1..500] of integer;
    m,n,i,l,j,p,k:integer;
    s,g,sr,d,o,h:real;
begin
readln(n);
readln(p);
for i:= 1 to n do readln(a[i]);
For j:=1 to n-1 do
    begin
    b[i]:=a[j+1]-a[j];
    c[i]:=a[j+1]-a[j];
    end;
for i:= 2 to n-1 do
    for j:=n downto 1 do
        if c[j-1]>c[j] then
        begin
        c[j-1]:=c[j-1]+c[j];
        c[j]:=c[j-1]-c[j];
        c[j-1]:=c[j-1]-c[j];
        end;
for l:=1 to p-1 do
    for m:=1 to n-1 do
        if b[m]=c[p-1] then
        begin;
        k:= k+1;
        r[k]:=m;
        end;
for i:= 2 to p-2 do
    for j:=p-1 downto 1 do
        if r[j-1]>r[j] then
        begin
        r[j-1]:=r[j-1]+r[j];
        r[j]:=r[j-1]-r[j];
        r[j-1]:=r[j-1]-r[j];
        end;
for j:=1 to p-2 do
    for i:=(r[j]+1) to (r[j+1]-1) do
    begin
    begin
    g:=a[i]+g;
    end;
    sr:=g/(r[i+1]-r[i]);
    for i:=(r[j]+1) to (r[j+1]-1) do
    begin
    d:=sqr(sr-a[i])+d;
    end;
    s:=s+d;
    end;
for i:= 1 to r[1] do
begin
begin
h:=h+a[i];
end;
sr:=h/(r[1]);
o:=sqr(sr-a[i])+o;
end;
s:=s+o;
writeln(s);
readln;
end.

