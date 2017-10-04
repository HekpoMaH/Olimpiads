program digit;
var
a,k,i:integer;
begin
readln(a);
if a<9 then k:=a else begin
if a mod 2 =1 then begin
 if ((a div 10) mod 2 =1) and (a mod 2 =1) then
  k:=(a mod 10) div 2;
 if ((a div 10) mod 2=0) and (a mod 2=1) then
  k:=((a mod 10) div 2) + 5;
 if a mod 2 = 0 then k:=(k div 10) div 2;
 end;
 end;
writeln(k);
end.