{$N+}
program dfrac;
var a,b,s:longint;
k:comp;
p,I:integer;
begin
readln(a,b);
a:=a*10;
readln(k,p);
for I:=1 to trunc(k)-1 do
a:=(a-(a div b)*b)*10;
for I:=1 to p do
begin
write(a div b);
a:=(a-(a div b)*b)*10
end
end.