Program Primes;

 Var A: Array[1..16000] of Longint;
     I, J, S, N, Br: Longint;

 Function Simple(Ch: Longint): Boolean;
  Var Z: Longint;
  Begin
   Simple := True;
   For Z := 2 to Trunc(sqrt(Ch)) do
    If Ch mod Z = 0 then Begin
                          Simple := False;
                          Break
                         End;
  End;

 Procedure Next(Var F: Longint);
  Begin
   Repeat
    Inc(F);
   Until (Simple(F));
  End;

 Begin
  ReadLn(N);
  If N = 1 then Begin WriteLn(0); Halt End;
  Repeat
   Inc(I);
   A[I] := 2;
   Inc(S, A[I]);
  Until S >= N;

  Repeat
   If (S = N) and (I <> 0) then
                 Begin
                  Inc(Br);
{                  For J := 1 to I do Write(A[J], ' ');
                  WriteLn;}
                 End;
   If S >= N then Begin
                   S := S - A[I] - A[I - 1];
                   A[I] := 0;
                   Dec(I);
                   Next(A[I]);
                   S := S + A[I];
                  End
             else Begin
                   Inc(I);
                   A[I] := A[I - 1];
                   S := S + A[I];
                  End;
  Until A[1] > N;
{  Write(Br);
  Write(#10,#13);}
  Next(N);
  Write(Br mod N);
  Write(#10, #13);
 End.
