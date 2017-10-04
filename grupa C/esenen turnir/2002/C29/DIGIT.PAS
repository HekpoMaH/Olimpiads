{Ilian Ivanov Ivanov 7 klas}
program digi;
var
w,br:real;
i,k:integer;
function brDigits(a:integer):integer;
var
br1,q:integer;
begin
q:=a;
br1:=0;
while q<>0 do begin
q:=q div 10;
br1:=br1+1;end;
brDigits:=br1;
end;
begin
readln(k);
br:=0;
for i:=1 to k do begin
w:=brDigits(i);
br:=br+1/w;
end;
readln;
end.