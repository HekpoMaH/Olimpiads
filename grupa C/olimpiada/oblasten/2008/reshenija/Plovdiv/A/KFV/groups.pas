var n,p,i,j,last:Longint;
    a:Array[1..500] of Real;
    vis:Array[1..500] of Boolean;
    mindifp:Longint;
    s,di,mindif:Real;

function fabs(x:real):real;
Begin
 if x>=0 then fabs:=x else fabs:=-x;
End;

Begin
  ReadLn(n,p);
 For i:=1 to n do Read(a[i]);
 For j:=1 to p-1 do
 Begin
   mindif:=maxlongint;
  For i:=2 to n-1 do
   if (not vis[i])and(not vis[i-1]) then
    if abs(a[i]-a[i+1])<mindif then
    //if not((i=1)and(abs(a[i+2]-a[i+1])=abs(a[i+1]-a[i]))) then
    Begin
      mindif:=fabs(a[i]-a[i+1]);
      mindifp:=i;
    End;
   vis[mindifp]:=True;
 End;
  last:=1;
  vis[n+1]:=true;
  di:=0;
 For i:=1 to n do
 Begin
   if vis[i+1] then
   Begin
     s:=0;
    For j:=last to i do s:=s+a[j];
     s:=s/(i-last+1);
    For j:=last to i do di:=di+sqr(a[j]-s);
     last:=i+1;
   End;
 End;
  WriteLn(di:0:4);
End.
