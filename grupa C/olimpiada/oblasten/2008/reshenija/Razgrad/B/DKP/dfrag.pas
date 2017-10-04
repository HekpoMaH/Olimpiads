var i,j:integer;
begin
i:=11;j:=11;
write(i mod j);
end.


 rt:=r;
 st:=s;
 writeln('st begins from',st);
 for i:=1 to n do
 begin
  if (st div b[i]>=2) or (st mod b[i]=0) then
  begin
   writeln('b[',i,']=',b[i]);
   r:=r+1;
   writeln('r=',r);
   st:=st-b[i];
   writeln('st=',st);
   if i=n then
   begin
    repeat
     st:=st-1;
     r:=r+1;
    until st=0;
   end;
  end;
 end;