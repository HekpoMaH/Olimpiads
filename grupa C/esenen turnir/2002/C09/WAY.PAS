Var F    :Text;
    N,i,j,A,B:Byte;
    M    :Array [1..45,1..3] Of Byte;
Begin
  Assign(F,'Way.inp');
  Reset(F);
  ReadLn(F,N);
  WriteLn(N);
  J:=0;
  For i:=1 to N-1 Do
    J:=J+i;
  For i:=1 To j Do
    ReadLn(F,M[i,1],M[i,2],M[i,3]);
  Close(F);
  Assign(F,'Way.out');
  Rewrite(F);
  Close(F);
End.