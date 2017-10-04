Program Frequencies;
Var N:Longint;
    A:String;
    B:string;
    c:array[1..100]of string;
    otg:String;
    brstr1,cifbr,i,j,proverb,lb,cifbr2,g:Longint;
Function ngc(brstr:Longint):Longint;
 Begin
   brstr1:=brstr;
  For brstr:=1 to brstr1 do Begin {Nachalo}
                              ReadLn(A); {prochita Stringut}
                              i:=1;
                              j:=1;
                              cifbr:=0;
                             Repeat       {\|/-proverka za figurirane v masiva b}
                             For proverb:=1 to Length(B) do  Begin
                                                             if  A[i]<>B[proverb] then Begin
                                                                                        Repeat {ako e ednakwo sus >then}
                                                                                         If A[i]=A[j+1] then cifbr:=cifbr+1;
                                                                                         j:=j+1;
                                                                                        Until (j=Length(A));
                                                                                        c[cifbr]:=A[i];
                                                                                        {}
                                                                                        insert(c[cifbr],B,cifbr);{prisvoqvane}
                                                                                        if (cifbr2<cifbr) then Begin
                                                                                                                cifbr2:=cifbr;
                                                                                                               g:=pos(A[i],B);
                                                                                                               End;
                                                                                       End;                   {prisvoqvane}
                                                             End;
                              i:=i+1;{ogolemqvane}
                             Until (i=Length(A)+1);
                            End;
End;
Begin
 Repeat
  Write('Enter N ');
  ReadLn(N);
 Until (2<N)and(N<10000);
  ngc(N);
  otg:=copy(B,g,1);
  lb:=cifbr2;
  WriteLn;
  WriteLn(otg,' ',g);
  ReadLn;
End.