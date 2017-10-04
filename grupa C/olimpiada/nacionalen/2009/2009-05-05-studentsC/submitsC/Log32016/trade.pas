{
TASK:TRADE
LANG:PASCAL
}

program trade;
var n,i,j,aux,k:longint;
    st:real;
    lg:array[1..100000] of longint;
    sum,val:array[1..100000] of real;

function ok:boolean;
begin
  ok:=true;
  for i:= 1 to n do
    if abs(val[i]+val[lg[i]]-sum[i]-sum[i])>0.001 then
      ok:=false;
end;

procedure afla;
var semn:byte;
    nxt:longint;
begin
  for i:= 1 to n do
    begin
      semn:=0;
      nxt:=i;
      repeat
        if semn =0 then
          val[i]:=val[i]+sum[nxt]
          else val[i]:=val[i]-sum[nxt];
        nxt:=lg[nxt];
        semn:=not semn;
      until nxt=i;
      if n mod 2 =0 then
        val[i]:=val[i]*-1;
    end;
end;

begin
 { assign(input,'trade.in'); reset(input);
  assign(output,'trade.out'); rewrite(output);  }
  readln(n);
  for k:=1 to n do
    begin
      read(i,j);
      if i>j then
       begin
         aux:=j;
         j:=i;
         i:=aux;
       end;
      if lg[i]<> 0 then
        begin
          lg[j]:=i;
          read(sum[j]);
        end
        else
          begin
            lg[i]:=j;
            read(sum[i]);
          end;

    end;
  afla;
  if not ok then
    begin
      writeln('impossible');
    end
    else
      begin
        for i:= 1 to n do
          write(val[i]:0:2,' ');
        writeln;
      end;

 { close(output);
  close(input); }
end.