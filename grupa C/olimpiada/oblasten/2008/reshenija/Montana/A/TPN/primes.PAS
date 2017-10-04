program dskjf;
uses crt;
type masiv=array [1..1000]of longint;
var ok:boolean;
    x,i,j,r,f:longint;
    m:masiv;
procedure prosti(x:longint; var m:masiv; var f:longint);
begin
f:=0;
for i:=1 to 1000 do
begin
m[i]:=0;
end;
for i:=2 to x do
begin
ok:=false;
for j:=2 to 100 do
begin
     if (i<>j)and(i mod j = 0) then
     begin
          ok:=true;
          break;
     end;
end;
if ok=false then
for r:=1 to x do
    if m[r]=0 then
    begin
         m[r]:=i;
         f:=f+1;
         break
    end;
end;
end;
function bps(m:masiv; f:longint):longint;
var t,z,y,k,s,d:longint;
begin
     t:=0;
     if x mod 2 = 0 then
     begin
          t:=1;
          z:=x div 2;
          y:=2;
     end
     else
     begin
         y:=1;
         z:= x div 2;
     end;
     k:=1;
     for s:=y to f do
         for d:=2 to (x div 2) do
         begin
         k:=1;
             repeat
                   if d*(z-k)+m[s] = x then
                   begin
                        t:=t+1;
                        break;
                   end;
                   k:=k+1;
             until z=k;
         end;
     bps:=(t-1)mod 11;
end;
begin
clrscr;
write('vavedi estestveno 4islo: ');
readln(x);
prosti(x,m,f);
write(bps(m,f))
end.

