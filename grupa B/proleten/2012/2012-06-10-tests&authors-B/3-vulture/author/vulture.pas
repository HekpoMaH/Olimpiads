program vulture;

type
 TVertex=record x,y,z:integer end;

const 
 Max_XY=500; Max_Z=500;
 Max_queue=longint(Max_XY)*longint(Max_XY)*(longint(Max_Z)+1);

var
 H,V:array[1..Max_XY,1..Max_XY] of longint;
 M,N,H_max,k,
 x1,y1,x2,y2:longint;

 Q:array[1..Max_queue] of TVertex;
 Marked:array[1..Max_XY,1..Max_XY,0..Max_Z] of longint; 
   { -1 means not_marked, >=0 - distance from Vs } 
 Prev:array[1..Max_XY,1..Max_XY,0..Max_Z] of TVertex; 

procedure ReadData;
 var i,j:longint;
 begin
  readln(M,N,k,H_max);
  for i:=1 to M do for j:=1 to N do readln(H[j,i],V[j,i]);
  readln(x1,y1);
  readln(x2,y2);
  { writeln(H[4,1],' ',V[4,1]); }
 end;

procedure BFS;
 var
  First,Last,z1,d1: longint;
  Vs,Vt,W: TVertex;
  Found:boolean;
 function SameV(V1,V2:TVertex):boolean;
  begin
   SameV:=(V1.x=V2.x) and (V1.y=V2.y) and (V1.z=V2.z);
  end; 
 procedure InitBFS;
  var i,j,l:longint; 
  begin
   First:=0; Last:=0; { init queue }
   with Vs do begin x:=x1; y:=y1; z:=0 end;
   with Vt do begin x:=x2; y:=y2; z:=0 end; 
   for i:=1 to N do for j:=1 to M do for l:=0 to H_max do 
    Marked[i,j,l]:=-1; { init marks }
   Marked[Vs.x,Vs.y,Vs.z]:=0; { mark Vs }
   Q[Last]:=Vs; inc(Last); { enqueue Vs }
   { writeln('Vs=',Vs.x,' ',Vs.y,' ',Vs.z,' d=',0); }
   Found:=SameV(Vs,Vt);
  end;
 procedure Try_Adj(x1,y1,z0:integer);
  var 
   z1:integer;
   b1,b2:boolean;
   V1:TVertex;
  begin
   { writeln('Try ',x1,' ',y1,' ',z0); }
   with V1 do begin x:=x1; y:=y1 end;
   b1:=(1<=x1) and (x1<=N) and (1<=y1) and (y1<=M);
   if b1 then begin
    z1:=z0-H[x1,y1]; V1.z:=z1;
    b2:=SameV(V1,Vt) or ((1<=z1) and (z1<=H_max));
    if b2 and (Marked[x1,y1,z1]<0) 
     then begin { vertex V1 is possible destination }
      { writeln(x1,' ',y1,' ',z1,' d=',d1+1); }
      Found:=SameV(V1,Vt);
      Marked[x1,y1,z1]:=d1+1;
      Prev[x1,y1,z1]:=W;
      Q[Last]:=V1; inc(Last); { enqueue V1 }
     end;
   end;
  end;
 begin
  InitBFS; 
  while (First < Last) and (not Found) do begin
   W:=Q[First]; inc(First); { W:=Q.Dequeue }
   with W do begin { try all adjasent }
    z1:=H[x,y]+z-k+V[x,y];
    { writeln(x,' ',y,' ',H[x,y],' ',z,' ',k,' ',V[x,y]); }
    d1:=Marked[x,y,z];
    Try_Adj(x+1,y,z1); 
    Try_Adj(x-1,y,z1); 
    Try_Adj(x,y+1,z1); 
    Try_Adj(x,y-1,z1); 
   end;
  end;
  If Found then begin
   d1:=Marked[Vt.x,Vt.y,Vt.z];
   writeln(d1);
   {    
   W:=Vt;
   while d1>=0 do with W do begin
    writeln(x,' ',y,' ',z);
    W:=Prev[x,y,z];
    dec(d1); 
   end;
   }
  end else writeln('crash');
  { 
  writeln('Last=',Last);
  }
 end;

begin
 ReadData;
 BFS;
end.

