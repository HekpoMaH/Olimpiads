var s,n,i,sy,br,k,br2,ok,t,l,m,j:integer;
    a:array[1 .. 3000] of integer;
begin
br:=0;
ok:=0;
readln(s,n);
for i := 1 to n do read(a[i]);

for i:=1 to n-1 do begin
 l:=a[i]; m:=i;
 for j:= i+1 to n do
  if a[j]>l then begin l:=a[j]; m:=j; end;
 a[m]:=a[i];
 a[i]:=l;
end;

for k:= 1 to n do begin
sy:=s;
i:=k;
br:=0;
repeat
br:=br + (sy div a[i]);
sy:=sy mod a[i];
i:=i+1;
until sy = 0;
if k=1 then br2:=br else if br<br2 then br2:=br;
end;


writeln(br2);
end.