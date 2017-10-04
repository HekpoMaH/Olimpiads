program way;
var
 {r:array[1..50] of integer;}
 vr:array[1..10,1..10] of integer;
 n,a,b,i,p,q,j:integer;
 fl:boolean;
 {procedure path(a:integer);
  begin
  fl:=false;
   repeat
   if (a=b) or (vr[a,b]=1) then fl:=true else begin
   i:=1;
   while (vr[a,i]<>1) or (i<>n) do
   i:=i+1;
   if vr[a,i]=1 then begin
    vr[a,i]:=0;
    vr[i,a]:=0;
    path(i);
   k:=k+1;
   r[k]:=i;
   end;
   end;
   until(fl=true) or (i=n);
 end;}
begin
 {k:=0;}
 readln(n);
 for p:=1 to n-1 do
 for q:=p+1 to n do begin
 read(i);
 read(j);
 readln(vr[i,j]);

 end;
 vr[j,i]:=vr[i,j];
 for i:=1 to n do
 vr[i,i]:=0;
 read(a);
 read(b);
 i:=0;
 if vr[a,b]=1 then begin writeln('2'); write(a,' ',b); end
  else write('0');
 readln;
 end.
