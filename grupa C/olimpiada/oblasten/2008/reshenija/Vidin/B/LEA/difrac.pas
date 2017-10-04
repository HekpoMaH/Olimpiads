var a,b,p,k,i,m:longint;
begin
readln(a,b);
readln(p,k);
m:=(a mod b)*10;
for i:= 1 to k+p-1 do begin
if i>= p then write(m div b);
m:=(m mod b)*10;
end;
end.