program rkeg;
  var   m,n: Integer;
        x,y:LongInt;
        b:char;
        bool:Boolean;
        A : Array[1..30000,1..31] of byte;
        Z : Array[1..60,1..1000] of byte;
        Q : Array[1..1000] of byte;
  procedure p (i,j:Integer);
    var t,f1,f2:Integer;

    begin
      bool:=false;
        BEGIN
          f1:=0;
          for t:=1 to n do
             if z[t,i]=z[t,j] then
               inc(f1)
               else
                 begin
                   dec(f1,40);
                   break;
                 end;
             if f1>0 then
             BEGin
               f2:=0;
               for t:=31 to 30+n do
                 if z[t,i]=z[t,j] then
                   inc(f2)
                 else
                   begin
                     dec(f2,40);
                     break;
                   end;
               if f2>0 then
                 begin
                   bool:=true;
                   exit;
                 end
               else
                 begin
                 {}  f2:=0;
                 {}  for t:=31 to 30+n do
                 {}    if z[t,i]=z[31+n-t,j] then
                 {}      inc(f2)
                 {}    else
                 {}      begin
                 {}        dec(f2,40);
                 {}        break;
                 {}      end;
                 {}    if f2>0 then
                 {}      begin
                 {}        bool:=true;
                 {}        exit;
                 {}      end;
                 end
             ENd
             else{f1<0}
               begin
                 f1:=0;
                 for t:=1 to n do
                   if z[t,i]=z[1+n-t,j] then
                     inc(f1)
                   else
                     begin
                       dec(f1,40);
                       break;
                     end;
                 if f1>0 then
                   BEGin
                     f2:=0;
                     for t:=31 to 30+n do
                       if z[t,i]=z[t,j] then
                         inc(f2)
                       else
                         begin
                           dec(f2,40);
                           break;
                         end;
                       if f2>0 then
                         begin
                           bool:=true;
                           exit;
                         end
                       else
                         begin
                         {}  f2:=0;
                         {}  for t:=31 to 30+n do
                         {}    if z[t,i]=z[31+n-t,j] then
                         {}      inc(f2)
                         {}    else
                         {}      begin
                         {}        dec(f2,40);
                         {}        break;
                         {}      end;
                         {}    if f2>0 then
                         {}      begin
                         {}        bool:=true;
                         {}        exit;
                         {}      end;
                         end;

                   ENd
                 else
                   begin
                     f1:=1;
                     for t:=1 to n do
                       if (z[t,i]=z[30+t,j])and (z[t,j]=z[30+t,i]) then
                         inc(f1)
                       else
                         begin
                           dec(f1,40);
                           break;
                         end;
                     if f1>0 then
                       begin
                         bool:=true;
                         exit;
                       end
                     else
                       begin
                         f1:=0;
                         for t:=1 to n do
                       if (z[t,i]=z[30+n-t,j])and (z[t,j]=z[30+n-t,i]) then
                         inc(f1)
                       else
                         begin
                           dec(f1,40);
                           break;
                         end;
                     if f1>0 then
                       begin
                         bool:=true;
                         exit;
                       end
                   end;
               end;

        END;

    end{of procedure};

begin
  readln(m,n);
  for x:=1 to 1000 do
    q[x]:=0;

  for y:=1 to 60 do
    for x:=1 to 1000 do
      z[y,x]:=0;
      for y:=1 to 60 do
    for x:=1 to 1000 do
      write(z[y,x]);
    for x:=1 to n do
    writeln(q[x]);

  for x:=1 to(m*n) do
    begin
      for y:=1 to n do
        begin
          read(b);
          if b='1' then
            begin
              a[x,y]:=1;
              inc(z[y,x]);
              inc(z[30+y,x]);
            end
          else a[x,y]:=0;
        end;
      readln;
    end;
  for x:=1 to (m*n) do
    begin
      for y:=1 to n do
        write(a[x,y],' ');
      writeln;
    end;
  readln;
  for x:=1 to m do
    for y:=1 to m do
      if (x<>y)and(q[x]=0)and(q[y]=0) then
        begin
          p(x,y);
          if bool=true then
            if x<y then
              q[x]:=1
            else
              q[y]:=1;
        end;
    for x:=1 to m do
      write( q[x]);
    readln;
 end.