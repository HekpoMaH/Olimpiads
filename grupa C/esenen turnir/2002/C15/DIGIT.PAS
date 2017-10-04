program manja;
var c,a,b,x:longint;
    s:string[9];
begin
     readln(c);
     if c<=9
        then writeln(c);
     if (C<=9+2*90) and (c>9)
        then begin
             a:=(c-9) div 2;
             x:=(c-9) mod 2;
             if x=0
                then b:=9+a
                else b:=9+a+1;
             str(b,s);
             writeln(s[length(s)-x]);
        end;
     if (C<=9+2*90+3*900) and (c>9+2*90)
        then begin
             a:=(c-9-2*90) div 3;
             x:=(c-9-2*90) mod 3;
             if x=0
                then b:=9+90+a
                else b:=9+90+a+1;
             str(b,s);
             if x=0
                then writeln(s[length(s)-x])
                else writeln(s[x]);
        end;
     if (C<=9+2*90+3*900+4*9000) and (c>9+2*90+3*900)
        then begin
             a:=(c-9-2*90-3*900) div 3;
             x:=(c-9-2*90-3*900) mod 3;
             if x=0
                then b:=9+90+900+a
                else b:=9+90+900+a+1;
             str(b,s);
             if x=0
                then writeln(s[length(s)-x])
                else writeln(s[x]);
        end;
     if (C<=9+2*90+3*900+4*9000+5*90000) and (c>9+2*90+3*900+4*9000)
        then begin
             a:=(c-9-2*90-3*900-4*9000) div 3;
             x:=(c-9-2*90-3*900-4*9000) mod 3;
             if x=0
                then b:=9+90+900+9000+a
                else b:=9+90+900+9000+a+1;
             str(b,s);
             if x=0
                then writeln(s[length(s)-x])
                else writeln(s[x]);
        end;
     if (C<=9+2*90+3*900+4*9000+5*90000+6*900000) and (c>9+2*90+3*900+4*9000+5*90000)
        then begin
             a:=(c-9-2*90-3*900-4*9000-5*90000) div 3;
             x:=(c-9-2*90-3*900-4*9000-5*90000) mod 3;
             if x=0
                then b:=9+90+900+9000+90000+a
                else b:=9+90+900+9000+90000+a+1;
             str(b,s);
             if x=0
                then writeln(s[length(s)-x])
                else writeln(s[x]);
        end;
     readln;
end.