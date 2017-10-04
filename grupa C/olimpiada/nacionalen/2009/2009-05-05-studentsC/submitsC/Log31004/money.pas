(*
TASK:MONEY
LANG:PASCAL
*)

program moneymoneymoney;
var n,i,fo:longint;
    income:array[1..200000] of longint;

procedure order;
var aux, sch : longint;
begin
  repeat
    sch:=0;
    for i := 1 to n-1 do
      if income[i]<income[i+1] then
        begin
          sch:=1;
          aux:=income[i];
          income[i]:=income[i+1];
          income[i+1]:=aux;
        end;
  until sch=0;
end;

begin
{  assign(input,'money.in'); reset(input);
  assign(output,'money.out'); rewrite(output); }
  readln(n);
  for i := 1 to n do read(income[i]);
  order;
  fo:=1;
  while income[fo+1]+income[fo]>income[1] do
    inc(fo);
  if fo=2 then fo:=1;
  writeln(fo);
 { close(input);
  close(output);}
end.