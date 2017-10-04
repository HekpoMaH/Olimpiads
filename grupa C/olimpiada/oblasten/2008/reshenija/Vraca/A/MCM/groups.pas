Program groups;
type gr=record
sa,d:real;
brt:integer;
tochki:array[1..500] of integer;
end;
var grupi:array [1..500] of gr;
tochkite:array [1..500] of real;
p,n,ci:integer;
sbr:real;

function sredno(id:integer):real;
var ki,bb:integer;
sboki,otg:real;
begin
sboki:=0;
bb:=grupi[id].brt;
for ki:=1 to bb do sboki:=sboki+tochkite[grupi[id].tochki[ki]];
otg:=sboki/bb;
sredno:=otg;
end;

function namerid(id:integer):real;
var di:integer;
sb:real;
begin
sb:=0;
for di:=1 to grupi[id].brt do sb:=sb+sqr(grupi[id].sa-tochkite[grupi[id].tochki[di]]);
namerid:=sb;
end;

procedure izchisli;
var jii:integer;
sbdi:real;
begin
sbdi:=0;
for jii:=1 to p do begin
grupi[jii].sa:=sredno(jii);
grupi[jii].d:=namerid(jii);
sbdi:=sbdi+grupi[jii].d;
end;

if sbdi<sbr then sbr:=sbdi;
end;

procedure rek(brti,poslta,grupanom:integer);
var ji:integer;
begin

if (grupanom<p)and((poslta+brti)<(n+1)) then
begin

with grupi[grupanom] do
begin
brt:=0;
for ji:=poslta to poslta+brti-1 do
begin
brt:=brt+1;
tochki[brt]:=ji;
end;
end;

for ji:=1 to n do rek(ji,poslta+brti,grupanom+1);
end;


if (grupanom=p)and((poslta+brti)=(n+1))  then begin
with grupi[p] do
begin
brt:=0;
for ji:=poslta to poslta+brti-1 do
begin
brt:=brt+1;
tochki[brt]:=ji;
end;
end;
izchisli;
end;

end;

begin
sbr:=500;
readln(n,p);
for ci:=1 to n do read(tochkite[ci]);
for ci:=1 to n do rek(ci,1,1);
writeln(sbr:0:4);
end.
