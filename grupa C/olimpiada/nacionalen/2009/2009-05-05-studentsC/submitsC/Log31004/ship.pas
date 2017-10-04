(*
TASK:SHIP
LANG:PASCAL
*)
program capitan_hook_s_ship;
type vector=array[0..10000] of longint;
var n,i,j,m:longint;
    min,sum,wht:int64;
    p,w:vector;
    gr:array[0..10000] of byte;

procedure group(i:longint);
begin
  while gr[p[i]]=0 do
    begin
      gr[p[i]]:=1;
      i:=p[i];
    end;
end;

function weight(ince:longint;pp,wp:vector):int64;
var wh:int64;
    aux:longint;
begin
  wh:=0;
  while pp[ince]<>ince do
    begin
      wh:=wh+wp[ince]+wp[pp[ince]];
      aux:=wp[ince];
      wp[ince]:=wp[pp[ince]];
      wp[pp[ince]]:=aux;
      aux:=pp[pp[ince]];
      pp[pp[ince]]:=pp[ince];
      pp[ince]:=aux;
   end;
  weight:=wh;
end;

begin
{  assign(input,'ship.in'); reset(input);
  assign(output,'ship.out'); rewrite(output);  }
  readln(n);
  for i:= 1 to n do
    read(w[i-1]);
  for i:= 1 to n do
    read(p[i-1]);
  for i:= 0 to n-1 do
    if (i<>p[i])and(gr[i]<>2) then
      begin
        {cream grupa}
        gr[i]:=1;
        group(i);
        min:=10000000000000000;
        {verifcam pentru fiecare inceput pusibil punctajul si selectam
        maximul
        si de ce dracu' vorbesc la pers 1 pl?}
        for j:= 0 to n-1 do
          if gr[j]=1 then
            begin
              wht:=weight(j,p,w);
              if wht<min then min:=wht;
            end;
        for j:= 0 to n do
          if gr[j]=1 then
          gr[j]:=2;
        sum:=sum+min;
      end;
  writeln(sum);
  {close(output);
  close(input); }
end.