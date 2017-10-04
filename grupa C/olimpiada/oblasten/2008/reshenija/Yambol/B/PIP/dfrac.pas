program b1;
var i,x,y,k,p:longint;
    z:real;
    a:string;
begin
readln(x,y);
readln(k,p);
z:=x/y;

str(z:1:1000000000,a);
for i:=k+2 to k+p+1 do
write(a[i]);

end.
