{
	Жадность с быстрым считыванием входных данных
}
{$APPTYPE CONSOLE}
{$B-,R-,O+}
const
 maxn=100001;
 maxm=100001;
 inf=1000000000;
var
 fi,fo:text;
 n,m,y0,y1,i,j,d,lastd:longint;
 a,b:array[1..maxn] of longint;
 ans:longint;
 hasnext,hascur:boolean;
 buf:array[0..65535] of char;
begin
 assign(fi,'mice.dat');
 assign(fo,'mice.sol');
 SetTextBuf(fi,buf);
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
 ans:=n;
 lastd:=-1;
 j:=1;
 for i:=1 to n do
  begin
   while(j<m)and(abs(b[j+1]-a[i])<abs(b[j]-a[i]))do
    begin
     inc(j);
     lastd:=-1;
    end;
   d:=abs(b[j]-a[i]);
   hasnext:=(j<m)and(abs(b[j+1]-a[i])=d);
   if(d<lastd)and(not hasnext)then
    inc(ans);
   if(lastd=-1)or(d=lastd)or((d<lastd)and(not hasnext))then
    begin
     dec(ans);
     lastd:=d;
    end else
   if(hasnext)then
    begin
     inc(j);
     dec(ans);
     lastd:=d;
    end;
  end;
 writeln(fo,ans);
 close(fi);
 close(fo);
end.
