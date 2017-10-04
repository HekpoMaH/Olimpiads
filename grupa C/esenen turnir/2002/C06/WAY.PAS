Program way;
var
bool,flag:boolean;
m:array[1..10,1..10] of byte;
r:array[1..10] of byte;
i,p,a,b,x,y,n,k:integer;
procedure path(z,q:integer);
 var
  c:integer;
 begin
 c:=1;
 if (z=q) or (m[z,q]=1) then flag:=true;
 if not flag then begin
 while (m[z,c]=0) and (c<=n) do
  c:=c+1;
 if m[z,c]=1 then begin
  m[z,c]:=0;
  m[c,z]:=0;
  path(c,q);
  m[c,z]:=1;
  m[z,c]:=1;
 end;
 end;
 if flag then
 begin
  p:=p+1;
  r[p]:=c;
 end;
 end;
begin
 flag:=false;
 bool:=false;
 p:=0;
 readln(n);
 repeat
  read(x);
  read(y);
  readln(k);
  m[x,y]:=k;
  m[y,x]:=k;
  if ((x=n-1) and (y=n)) or ((y=n-1) and (x=n)) then bool:=true;
 until bool;
 read(a);
 readln(b);
 path(a,b);
 if flag then begin
 p:=p+1;
 r[p]:=a;
 r[1]:=b;
 writeln(p);
 for i:=p downto 1 do
 write(r[i],' ');
 writeln;
 end
 else write('0');
end.