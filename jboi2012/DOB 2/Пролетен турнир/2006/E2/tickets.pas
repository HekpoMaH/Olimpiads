var a,b,i:longint;
    i1,i2,i3:byte;
    counter:longint;
begin
readln(a,b);
counter:=0;
for i:=a to b do
  begin
    i1:=(i div 10000)+((i mod 10000) div 1000);
    i2:=(i mod 1000) div 100;
    i3:=(i mod 100) div 10 + (i mod 10);
    if (i1=i2) and (i2=i3) then
      begin
       {
        if i<10 then write('0');
        if i<100 then write('0');
        if i<1000 then write('0');
        if i<10000 then write('0');
        writeln(i);
       }
       counter:=counter+1;
      end;
  end;
 writeln(counter);
end.