Program freq;
var
s:string;
i,n:integer;
br,mx:byte;
mxc:char;
procedure search(x:string);
 var
 j,l,k:byte;
 begin
  l:=length(x);
  for j:=1 to l do begin
   br:=1;
   if x[j]<>' ' then
    for k:=1 to l do
     if (j<>k) and (x[k]=x[j]) then
      br:=br+1;
   if mx<br then
    begin mx:=br; mxc:=x[j]; end;
  end;
 end;
begin
 mx:=0;
 readln(n);
 for i:=1 to n do begin
  readln(s);
  search(s);
 end;
 write(mxc,' ',mx);
end.