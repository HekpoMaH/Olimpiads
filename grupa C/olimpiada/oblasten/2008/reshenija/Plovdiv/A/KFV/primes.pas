{$S-}
const
   max = 60000;
var  prime , vis: array[1..max] of boolean;
     pn,cnt:Array [0..max] of Longint;
     l,n,i,j,temp:Longint;

procedure eratos;
  var
    i,j : longint;

begin
  prime[1]:=false;
 for i:=2 to n+10000 do
  prime[i]:=true;
 for i:=2 to (n+10000) div 2 do
  if prime[i] then
   for j:=2 to (n+10000) div i do
     prime[i*j]:=false;
 for i:=2 to (n+10000) do
  if prime[i] then
  Begin
    l:=l+1;
    pn[l]:=i;
   If i>=n then break;
  End;
end;

Function dig(x: Longint; epi:Longint):Longint;
var i,br:Longint;
Begin
  //WriteLn(x,' ',pn[epi],' start');
 If cnt[x]>0 then
 Begin
   dig:=cnt[x];
   //WriteLn(x,' ',pn[epi],' finish ',cnt[x]);
   Exit;
 End;
  {br:=0;}
 {If temp=0 then
 Begin
   br:=(br+1)mod pn[l];
   Exit;
 End;}
 If x=0 then Exit;
 For i:=epi downto 1 do
  If x-pn[i]>=0 then
  Begin
   If (x=n)and(n mod 2=1) and(pn[i]=2) then break;
    {temp:=temp-pn[i];
    cnt[x]:=cnt[x]+dig(i);
    temp:=temp+pn[i];}
   If x-pn[i]<>1 then
   {If not vis[pn[i]] then}
   Begin
     //WriteLn(x,'-',pn[i]);
     cnt[x]:=(cnt[x]+dig(x-pn[i],i))mod pn[l];
     {vis[pn[i]]:=true;}
     //WriteLn(x,' Status ',cnt[x]);
   End;
  End;
  dig:=cnt[x];
  //WriteLn(x,' ',pn[epi],' finish ',cnt[x]);
End;

Begin
  ReadLn(n);
  eratos;
  temp:=n;
  cnt[2]:=1;
  cnt[3]:=1;
  WriteLn(dig(n,l-1));
End.
