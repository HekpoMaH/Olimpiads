program manja;
var a,b,c,x,y,z,n,Br,i,j,Br2:byte;
    vr:array[1..10,1..10] of byte;
    res:array[1..10] of byte;
    t:boolean;
Procedure Path(a:byte);
begin
     c:=b;
     if (a=b) or (vr[a,b]=1)
        then t:=true
        else begin
             c:=c+1;
             vr[c,a]:=0;
             vr[a,c]:=0;
             if c<=n then Path(c);
             i:=i+1;
             vr[c,a]:=1;
             vr[a,c]:=1;
        end;
     if t=true
        then res[i]:=c;
end;


begin
     readln(n);
     Br:=0;
     for i:=1 to n do
         for j:=1 to n do vr[i,j]:=0;
     for i:=(n-1) downto 1 do Br:=Br+i;
     for i:=1 to br do begin
         readln(x,y,z);
         if z=1
            then begin
                 vr[x,y]:=1;
                 vr[y,x]:=1;
            end;
     end;
     readln(a,b);
if (a=b) or (vr[a,b]=1)
   then begin
        if (a=1) and (b=1)
           then writeln('1')
           else writeln('2');
        write(a,' ',b);
   end
   else begin
     for i:=1 to 10 do res[i]:=0;
     i:=1;
     Path(a);
     if res[2]>0
        then res[1]:=a;
     Br2:=0;
     for i:=1 to 10 do
         if res[i]>0
            then Br2:=Br2+1;
     if res[1]>0
        then writeln(Br2)
        else write(Br2);
     for i:=1 to 10 do
         if res[i]>0
            then write(res[i],' ');
   end;
     readln;
end.