var
 i,j,k,l:byte;
 n:byte;
 fl:boolean;
 wa:array [1..10,1..10] of boolean;
 way:array [1..100] of byte;
 a,b:byte;
 w:byte;

 procedure Inp;
  var
   t:text;
  begin
    assign (t,'way.inp');
    reset (t);
    readln (t,n);
    for i:=1 to n-1 do
     for j:=i+1 to n do
      begin
        readln (t,k,k,k);
        if k=0 then
         begin
          wa[i,j]:=false;
          wa[j,i]:=false;
         end
        else
         begin
           wa[i,j]:=true;
           wa[j,i]:=true;
         end;
      end;
    readln (t,a,b);
    close (t);
  end;

  procedure Out;
   var
    t:text;
   begin
     assign (t,'way.out');
     rewrite (t);
     writeln (t,w);
     for i:=1 to w do
      if i=w then
       write (t,way[i])
      else
       write (t,way[i],' ');
     close (t);
   end;

   procedure Del(ind:integer; var a:array of byte);
    var
     i,j,k,l:integer;
    begin
      for i:=ind to SizeOf(a)-1 do
       a[i]:=a[i]+1;
      a[SizeOf(a)]:=0;
    end;

begin
Inp;
w:=1;
way[w]:=a;
k:=a;
repeat
  for i:=1 to n do
   if wa[k,i]=true then
    begin
      w:=w+1;
      way[w]:=i;
      wa[k,i]:=false;
      wa[i,k]:=false;
      k:=i;
      break;
    end;
until way[w]=b;
Out;
end.