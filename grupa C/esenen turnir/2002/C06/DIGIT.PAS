Program digit;
var
a,k:longint;
begin
 readln(k);
 case k of
  1..9: a:=k;
  10..190: begin
   a:=(k+9) div 2;
   if (k mod 10) mod 2=0 then a:=a div 10 else a:=a mod 10;
  end;
  191..2891: begin
  a:=(k+109) div 3;
   if k mod 3=0 then a:=(a div 10) mod 10 else
   if k mod 3=1 then a:=a mod 10
   else a:=((a div 10) div 10) mod 10;
  end;
  end;
  if (k>=2891) and (k<=38891) then begin
   a:=(k+1109) div 4;
   if k mod 4=0 then a:=a mod 10 else
    if k mod 4=1 then a:=(a mod 10) mod 10 else
     if k mod 4=2 then a:=((a mod 10) mod 10) mod 10;
      if k mod 4=3 then a:=(((a mod 10) mod 10) mod 10) mod 10;
  end;
  write(a);
end.
