var
 N,i,j,br,K,sum,x,y,number,remain            : longint;
begin
 readln(K);
 sum:=sum;
 for i:=1 to 8 do
  begin
   n:=1;
   for j:=1 to i-1 do
   n:=n*10;
   sum:=sum+(9*n*i);
   if (K<=sum) then
    begin
     br:=sum-(9*n*i);
     x:=(k-br) div i;
     y:=(k-br) mod i;
     number:=n+x-1;
     for j:=2 to y do
     n:=n div 10;
     if y=0 then writeln(number mod 10)
       else
        begin
         remain:=((number+1) div n) mod 10;
         writeln(remain);
        end;
     break;
    end;
  end;
end.