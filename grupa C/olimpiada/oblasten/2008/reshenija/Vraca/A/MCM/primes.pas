Program primes;
var vhod,broi,ci:longint;

function eprosto(koe:longint):boolean;
var i:longint;
dali1:boolean;
begin
dali1:=true;
i:=1;
repeat
i:=i+1;
if (koe mod i)=0 then dali1:=false;
until (i=koe div 2)or(not dali1);
if koe<4 then dali1:=true;
if koe=1 then dali1:=false;
eprosto:=dali1;
end;

function slpr(chlo:longint):longint;
var ii:longint;
begin
ii:=chlo;
repeat
ii:=ii+1;
until eprosto(ii);
slpr:=ii;
end;

procedure rek(chlo,sbor{bez chlo}:longint);
var ji:longint;
begin
if chlo<vhod then
begin
if sbor+chlo<vhod then
begin
for ji:=chlo to vhod do if eprosto(ji) then rek(ji,sbor+chlo);
end;
if sbor+chlo=vhod then begin
broi:=broi+1;
end;
end;
end;

begin
broi:=0;
readln(vhod);
for ci:=2 to vhod do if eprosto(ci) then rek(ci,0);
writeln(broi mod slpr(vhod));
end.
