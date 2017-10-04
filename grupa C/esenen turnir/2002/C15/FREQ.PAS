Program manja;
var N,i,Poz,j,Br,BrM,k:integer;
    S,T:string;
    p:string[1];
begin
     readln(n);
     BrM:=0;
     for i:=1 to n do begin
         S:='';
         readln(S);
         j:=1;
         Poz:=1;
         for j:=1 to Length(s) do begin
             Br:=0;
               if S[j]<>' '
                  then begin
                       Br:=1;
                       Poz:=1;
                       T:=S[j];
                       delete(s,j,1);
                       while Poz<>0 do begin
                             Poz:=Pos(T,s);
                             if Poz>0
                                then begin
                                     delete(s,Poz,1);
                                     Br:=Br+1;
                                end
                                else if Br>BrM
                                     then begin
                                          BrM:=Br;
                                          p:=T;
                                     end;
                       end;
                  end;

         end;
     end;
     write(p,' ',BrM);
     readln;
end.