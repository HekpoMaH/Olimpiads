program b2;
var i,j,m,n,x,ssum,sum:integer;
    z:string;
    A:array[1..1000,1..30,1..30] of byte;


  function savpada(k,l:integer):boolean;
   var j,x : integer;
       da:boolean;
  begin
   savpada:=true;
    for j:=1 to n do
     for x:=1 to n do
      if A[k,j,x]<>A[l,j,x] then
       begin
        savpada:=false;
        break;
       end;

   end;


  function lqva(k,l:integer):boolean;
    var j,x:integer;
   begin
    lqva:=true;
     for j:=1 to n do
      for x:=1 to n do
       if A[k,j,x]<>A[l,(n+1-x),j] then
        begin
         lqva:=false;
         break;
        end;
   end;


 function dqsna(k,l:integer):boolean;
   var j,x:integer;
  begin
   dqsna:=true;
    for j:=1 to n do
     for x:=1 to n do
      if A[k,j,x]<>A[l,x,(n-j+1)] then
       begin
        dqsna:=false;
        break;
       end;
  end;


  function obarnata(k,l:integer):boolean;
    var j,x:integer;
   begin
    obarnata:=true;
    for j:=1 to n do
     for x:=1 to n do
      if A[k,j,x]<>A[l,n-j+1,x] then
       begin
        obarnata:=false;
        break;
       end;
   end;



begin
readln(m,n);
for i:=1 to m do
 for j:=1 to n do
  begin
   readln(z);
    for x:=1 to n do
     if z[x]='0' then
      A[i,j,x]:=0
     else
      A[i,j,x]:=1;
  end;



  sum:=1;
  ssum:=0;
  x:=1;
for i:=2 to m do

begin


  for j:=i-1 downto x do
    if savpada(j,i) or lqva(j,i) or dqsna(j,i) or obarnata(i,j) then
      begin
       x:=i;
       ssum:=1;
       break;



      end
    else
     begin


      if ssum>sum then
       sum:=ssum;
     end;
inc(ssum);
end;
writeln(sum);

end.







