{$S-}
var s,temp:String;
    a:Array[1..50] of Longint;
    br,i:Longint;
    answer:QWord;

function cbp(s:String;startpos:Integer):Integer;
var i,target,co,cc:Integer;
Begin
  co:=0;
  cc:=0;
  target:=0;
 For i:=startpos to length(s) do
 Begin
  If s[i]='(' then co:=co+1;
  If s[i]=')' then cc:=cc+1;
  if co=cc then
  Begin
    target:=i;
    Break;
  End;
 End;
  cbp:=target;
End;

procedure rec(s:String);
var i:Longint;
    c:Char;
    lastthree:String;
Begin
  i:=0;
  lastthree:='   ';
 While i<length(s) do
 Begin
   i:=i+1;
   c:=s[i];
   delete(lastthree,1,1);
   lastthree:=lastthree+c;
  If c='+' then
  Begin
   If lastthree[1]=c then br:=br+1;
  End;
  If c='-' then
  Begin
   If lastthree[1]='+' then br:=br+1;
  End;
  If c='/' then
  Begin
   If lastthree[1]='*' then br:=br+1;
  End;
  If c='*' then
  Begin
   If lastthree[1]=c then br:=br+1;
  End;
  {If c='^' then
  Begin
   If lastthree[1]='^' then br:=br+1;
  End;}
  If c='(' then
  Begin
    rec(copy(s,i+1,cbp(s,i)-i-1));
    i:=cbp(s,i);
    lastthree[3]:=')';
   If lastthree[1]=')' then br:=br+1;
  End;
 End;
End;

Begin
  ReadLn(s);
  rec(s);
  answer:=1;
 If br>0 then
  For i:=1 to br do answer:=answer*2;
  WriteLn(answer);
End.