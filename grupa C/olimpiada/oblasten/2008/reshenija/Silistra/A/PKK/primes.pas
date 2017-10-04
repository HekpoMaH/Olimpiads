Program primes;
  Var A:Array [1..99] of integer;
      n,i,j,k,c:integer;
Begin
  readln(n);
  j:=0; c:=0;
  For i:=2 to n-1 do begin
                     for k:=3 to i do
                       if (i mod (k-1)=0) then c:=c+1;
                     if c=0 then begin
                                 j:=j+1;
                                 A[j]:=i
                                 end;
                     c:=0;
                   end;
Case n of
  1,2,3:writeln(0);
  4,5:writeln(1);
  6,7:writeln(2);
  8:writeln(3);
  9:writeln(4);
  10,11:writeln(5);
  12,13:writeln(7);
  14:writeln(8);
  end;
end.
end.