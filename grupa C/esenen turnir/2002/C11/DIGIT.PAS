Var
 I : Integer;
 S : String;
 B, N : Byte;


Begin
 ReadLn(I);

 B := 0; S := ''; N := 0;
 For I := I downto 1 do
  Begin
   If B = Length(S) then
    Begin
     Inc(N);
     Str(N, S);
     B := 1;
    end
    else Inc(B);
  end;
 Write(S[B]);
end.