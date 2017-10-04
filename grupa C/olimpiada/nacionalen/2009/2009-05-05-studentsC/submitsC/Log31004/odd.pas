{
TASK:ODD
LANG:PASCAL
}
program odd_version_2;
var n,i,nr:longint;
    od:array[1..1000000] of int64;

procedure order;
var aux, sch : int64;
begin
  repeat
    sch:=0;
    for i := 1 to n-1 do
      if od[i]<od[i+1] then
        begin
          sch:=1;
          aux:=od[i];
          od[i]:=od[i+1];
          od[i+1]:=aux;
        end;
  until sch=0;
end;


begin
 { assign(input,'odd.in'); reset(input);
  assign(output,'odd.out'); rewrite(output); }
  read(n);
  for i:= 1 to n do
    read(od[i]);
  order;
  i:=0;
  while i<n do
    begin
      inc(i);
      nr:=1;
      while (od[i]=od[i+1]) and(i<n-1) do
        begin
          inc(i);
          inc(nr);
        end;
      if nr mod 2 =1 then
        begin
          writeln(od[i]);
          break;
        end
    end;
{  close(output);
  close(input); }
end.