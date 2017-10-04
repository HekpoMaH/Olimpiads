var p, pp: double;
    i, k: integer;
function d(x: double): double;
var xa, xb: double;
    i, q: longint;
begin
  q:=trunc(sqrt(x));
  i:=q;
  while (abs(x-trunc(x/i)*1.*i) > 5e-5) and (i>=2) do i:=i-1;
  if i<2 then d:=1
         else begin
           xa:=i; xb:=round(x/i);
           d:=xa*d(xb)+d(xa)*xb;
{ writeln(xa:3:0,' ',xb:3:0);  }
         end;
end;

begin
  readln(p,k);
  pp:=p;
  for i:=1 to k do begin
    pp:=d(pp);
  end;
  writeln(pp:3:0)
end.