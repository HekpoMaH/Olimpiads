Var n:Longint;
    a,b,x,y,h1,h2:Longint;
    p:Array [1..150,1..150] of Byte;
    i,j,m,br:Longint;
    otg,otg1,otg2,otg3:Longint;
Function way(x1:Longint,y1:Longint):Longint;
Begin
  {a:=x;}
  for i:=1 to n do Begin
                   otg:=2;
                   Repeat
                     if (p[x,i]=1) then Repeat
                                          otg:=otg+1;



Begin
  ReadLn(n);
  For a:=1 to n do for b:=1 to n do Begin
                                      Write(a,' ',b,' ');
                                      ReadLn(p[a,b]);
                                    End;
  ReadLn(x,y);
  if p[x,y]=1 then Begin
                     Writeln('2');
                     writeln(x,' ',y);
                   End
              Else way(x,y);
End.