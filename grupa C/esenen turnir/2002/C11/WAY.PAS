Var
 N, B1, B2, B3, B4, A, B : Byte;
 Ar1 : Array[1..11,1..11] of Byte;
 Ar2 : Array[1..11] of Byte;

Begin
 ReadLn(N);

 For B1 := 1 to 11 do
  For B2 := 1 to 11 do
   Ar1[B1, B2] := 0;
 For B1 := 1 to N - 1 do
  For B2 := B1 + 1 to N do
   Begin
    ReadLn(B3, B4, A);
    Ar1[B3, B4] := A;
    Ar1[B4, B3] := A;
   end;
 ReadLn(A, B);

 For B1 := 1 to 11 do Ar2[B1] := 1;
 Ar2[1] := A; B1 := 2; B2 := 255;
 Repeat
  While (Ar1[Ar2[B1 - 1], Ar2[B1]] = 0) and (Ar2[B1] <= N)
   do Inc(Ar2[B1]);
  If (Ar2[B1] > N) or ((Ar2[B1] <= N) and (B1 = 10)) then
   Begin
    Ar2[B1] := 0;
    Dec(B1);
    Inc(Ar2[B1]);
   end
   else
    Begin
     Inc(B1);
     Ar2[B1] := 1;
    end;
  If (Ar2[B1 - 1] = B) then If (B1 - 1) < B2 then B2 := B1 - 1;
 Until (B1 = 1);

 If B2 = 255 then Write(0)
  else
   Begin
    For B1 := 1 to 11 do Ar2[B1] := 1;
    Ar2[1] := A; B1 := 2;
    Repeat
     While (Ar1[Ar2[B1 - 1], Ar2[B1]] = 0) and (Ar2[B1] <= N)
      do Inc(Ar2[B1]);
     If (Ar2[B1] > N) or ((Ar2[B1] <= N) and (B1 = 10)) then
      Begin
       Ar2[B1] := 0;
       Dec(B1);
       Inc(Ar2[B1]);
      end
      else
       Begin
        Inc(B1);
        Ar2[B1] := 1;
       end;
     If (Ar2[B1 - 1] = B) then If (B1 - 1) < B2 then B2 := B1 - 1;
    Until (Ar2[B1 - 1] = B) and (B1 - 1 = B2);

    WriteLn(B1 - 1);
    For B2 := 1 to B1 - 1 do
     Begin
      Write(Ar2[B2]);
      If B2 < (B1 - 1) then Write(' ');
     end;
   end;
end.