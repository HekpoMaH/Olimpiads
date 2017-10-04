var ch,mw:char;
     f:text;
     n,i:word;
     S:string;
     j,k,l,a1,mn:byte;
     m:array[1..256,1..200] of byte;
begin
  assign(F,'freq.inp');
  Reset(F);
  ReadLn(F,n);
  for i:=1 to n do
  Begin
    mn:=1;
    readln(f,s);
    j:=length(S);
    for l:=1 to j do
    Begin

      k:=pos(' ',S);
      if k<>0 then delete(s,k,1);
    end;
    ch:=s[1];
    For k:=1 to j do
    begin
      m[i,k]:=pos(ch,s);
      if m[i,k]<>0 then
      Begin
        inc(mn);
        delete(s,m[i,k],1);
      End;
    end;
  End;
  close(F);
  Assign(f,'freq.out');
  rewrite(f);
  close(F);
End.