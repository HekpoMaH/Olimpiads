Var
 N, M1, M2 : LongInt;
 S : String;
 B1, B2 : Byte;
 Ar : Array[1..26] of LongInt;
 C1, C2 : Char;

Begin
 ReadLn(N);
 For N := N downto 1 do
  Begin
   ReadLn(S);
   For B1 := 1 to 26 do Ar[B1] := 0;

   M2 := 0;
   For B1 := Length(S) downto 1 do
    Begin
     If S[B1] in ['a'..'z'] then
      Begin
       Inc(Ar[Ord(S[B1]) - 96]);
       If Ar[Ord(S[B1]) - 96] > M2 then
        Begin
         M2 := Ar[Ord(S[B1]) - 96];
         C2 := S[B1];
        end;
      end;

     If M2 > M1 then
      Begin
       M1 := M2;
       C1 := C2;
      end;
    end;
  end;

 N := 0;
 {For B1 := 1 to 26 do If Ar[B1] > N then N := Ar[B1];}
 {For B1 := 1 to 26 do If Ar[B1] = N then }
 Write(C1, ' ', M1);
end.