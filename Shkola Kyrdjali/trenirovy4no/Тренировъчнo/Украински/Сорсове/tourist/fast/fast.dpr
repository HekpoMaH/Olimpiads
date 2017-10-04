{
	O(n*logn) решение через наибольшую возрастающую последовательность.
}
{$APPTYPE CONSOLE}
{$B-,R-,O+}
const
 maxn = 100001;
type
 point=record
  x,y:int64;
 end;
var
 fi,fo:text;
 n,v,i,ans0,ans1:longint;
 x,t:array[1..maxn] of longint;
 p:array[1..maxn] of point;
 last:array[1..maxn] of longint;
procedure swap(var a,b:point);
var
 x:point;
begin
 x:=a;
 a:=b;
 b:=x;
end;
procedure Sort(l,r:longint);
var
 i,j:longint;
 k:point;
begin
 if(l<r)then
  begin
   i:=l;
   j:=r;
   k:=p[l+random(r-l+1)];
   repeat
    while(p[i].x<k.x)or((p[i].x=k.x)and(p[i].y<k.y)) do inc(i);
    while(p[j].x>k.x)or((p[j].x=k.x)and(p[j].y>k.y)) do dec(j);
    if(i<=j)then
     begin
      swap(p[i],p[j]);
      inc(i);
      dec(j);
     end;
   until i>j;
   Sort(l,j);
   Sort(i,r);
  end;
end;
function calc(hasTransport:longint):longint;
var
 i,j,k:longint;
 l,r,mid:longint;
 ans:longint;
begin
 k:=0;
 for i:=1 to n do
  begin
   l:=k+1;
   r:=0;
   while(l-r>1)do
    begin
     mid:=(l+r)div 2;
     if(last[mid]<=p[i].y)then
      r:=mid else
      l:=mid;
    end;
   last[l]:=p[i].y;
   if(l=k+1)then
    inc(k);
  end;
 calc:=k;
end;
begin
 assign(fi,'tourist.dat');
 assign(fo,'tourist.sol');
 reset(fi);
 rewrite(fo);
 readln(fi,n);
 for i:=1 to n do
  readln(fi,x[i],t[i]);
 readln(fi,v);
 for i:=1 to n do
  begin
   p[i].x := -x[i] + int64(v)*t[i];
   p[i].y := x[i] + int64(v)*t[i];
  end;
 Sort(1,n);
 ans1 := calc(1);
 i:=1;
 while(i<=n)do
  begin
   if(p[i].x<0)or(p[i].y<0)then
    begin
     swap(p[i],p[n]);
     dec(n);
    end else
    begin
     inc(i);
    end;
  end;
 Sort(1,n);
 ans0:=calc(0);
 writeln(fo,ans0,' ',ans1);
 close(fi);
 close(fo);
end.
