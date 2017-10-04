{$APPTYPE CONSOLE}
{$B-,R-,O+}
const
 maxn=100001;
 maxm=100001;
 inf=1000000000;
var
 fi,fo:text;
 n,m,y0,y1,i,j:longint;
 a,b:array[0..maxn] of longint;
 p:array[1..maxm] of longint;
 ans:longint;
 hasnext:boolean;
function match(i,j:longint;hasnext:boolean):boolean;
var
 d1,d2:longint;
begin
 d1:=abs(a[i]-b[j]);
 d2:=abs(a[p[j]]-b[j]);
 if(p[j]<>0)and(d1<d2)and(not hasnext)then
  inc(ans);
 if(p[j]=0)or(d1=d2)or((d1<d2)and(not hasnext))then
  begin
   p[j]:=i;
   dec(ans);
   match:=true;
  end else
   match:=false;
end;
begin
 assign(fi,'mice.dat');
 assign(fo,'mice.sol');
 reset(fi);
 rewrite(fo);
 readln(fi,n,m,y0,y1);
 if(m=0)then
  begin
   writeln(fo,n);
   close(fi);
   close(fo);
   halt;
  end;
 for i:=1 to n do
  read(fi,a[i]);
 readln(fi);
 for i:=1 to m do
  read(fi,b[i]);
 a[n+1]:=inf;
 fillchar(p,sizeof(p),0);
 ans:=n;
 j:=1;
 for i:=1 to n do
  begin
   while(j<m)and(b[j+1]<a[i])do
    inc(j);
   if(j<m)and(abs(b[j+1]-a[i])<abs(b[j]-a[i]))then
    inc(j);
   hasnext:=(j<m)and(abs(b[j+1]-a[i])=abs(b[j]-a[i]));
   if(not match(i,j,hasnext))then
    begin
     if(hasnext)then
      begin
       inc(j);
       match(i,j,false);
      end;
    end;
  end;
 writeln(fo,ans);
 close(fi);
 close(fo);
end.
 