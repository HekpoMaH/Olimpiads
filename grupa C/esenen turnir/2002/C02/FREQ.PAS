program freq;
var
 a:string;
 fi:text;
 k,maxk:char;
 l,maxl,n,i:integer;
 procedure broj (a:string;var k:char;var l:integer);
  var
   i,j,max,br:integer;
   m:char;
  begin
   max:=0;
  for i:=1 to length(a) do begin
    m:=a[i];
    br:=0;
    j:=pos(a[i],a);
   if a[i]<>' ' then begin
    repeat
     br:=br+1;
     if br>max then begin max:=br; k:=m; l:=br; end;
     a[j]:=' ';
     j:=pos(m,a);
     until j=0;
   end;
  end;
 end;
begin
 assign(fi,'freq.inp');
 reset(fi);
 readln(fi,n);
 maxl:=0;
 for i:=1 to n do begin
  readln(fi,a);
  broj(a,k,l);
  if l>maxl then begin maxl:=l; maxk:=k; end;
 end;
 writeln(maxk,' ',maxl);
 close(fi);
 end.




