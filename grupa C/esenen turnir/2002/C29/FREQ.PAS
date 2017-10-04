{Ilian Ivanov Ivanov, 7 klas}
program chest;
var
b:string;
n,i,j,k,br,br1,brMax:integer;
q,q1,q2:char;
begin
readln(n);
br1:=0;
for i:=1 to n do begin
readln(b);
      for j:=1 to length(b) do begin
          if b[j]<>' '
          then begin
          br:=1;
          for k:=j+1 to length(b) do
          if b[j]=b[k]
          then begin
          br:=br+1;
          q:=b[k];end;
      if br1<br
      then begin
           br1:=br;
           q1:=q;
           end;end;end;
if brMax<br1
then begin
brMax:=br1;
q2:=q1;end;end;
writeln(q2,' ',brMax);
readln;
end.
