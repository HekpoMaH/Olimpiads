var
 M                                            : array[1..10,1..10] of longint;
 BFS,BFS2,BFS3,BFS4                                          : array[1..10] of longint;
 i,j,n,k,br,cursor,a,b,c,start,kraj           : longint;
 Bool                                         : array[1..10] of boolean;
 f                                            : boolean;
begin
 readln(N);
 for i:=1 to ((n*(N-1)) div 2) do
  begin
    read(a);
    read(b);
    read(c);
    readln;
    M[a,b]:=c;
    M[b,a]:=c;
  end;
  read(start);
  read(kraj);
  readln;
  for i:=1 to n do
   begin
    BFS[i]:=0;
    Bool[i]:=false;
    BFS2[i]:=0;
    BFS3[i]:=0;
    BFS4[i]:=0;
   end;
  BFS[1]:=start;
  BFS2[1]:=1;
  BFS4[1]:=start;
  cursor:=0;
  br:=1;
  f:=false;
  BOOL[start]:=true;
  if start=kraj  then f:=true;
  while not f and ((BFS[cursor]<>0) or (cursor=0)) do
   begin
    cursor:=cursor+1;
    for i:=1 to N do
    if not Bool[i] and (M[BFS[cursor],i]=1) then
     begin
      br:=br+1;
      BFS[br]:=i;
      Bool[i]:=true;
      BFS2[br]:=BFS2[cursor]+1;
      BFS4[i]:=BFS[cursor];
      if i=kraj then
       begin
        f:=true;
        break;
       end;
     end;
   end;
 if not f then writeln(0)
    else
     begin
      writeln(BFS2[br]);
      a:=BFS[br];
      b:=1;
      BFS3[1]:=BFS[br];
      for i:=1 to BFS2[br]-1 do
       begin
        b:=b+1;
        a:=BFS4[a];
        BFS3[b]:=a;
       end;
    {  BFS3[1]:=start;
      for j:=2 to  BFS2[br] do
      if BFS4[j]=a then
       begin
        a:=BFS4[j];
        b:=b+1;
        BFS3[b]:=a;
       end; }
        for i:=b downto 1 do
         begin
          write(BFS3[i]);
          if i>1 then write(' ');
         end;
       writeln;
     end;
end.