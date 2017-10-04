var
 i:integer;
 n:integer;
 s:string;
 c:char;
 b:byte;

 function MaxNum(s:string):integer;
  var
   i,j,k:integer;
   c:char;
   n:integer;
  begin
    n:=0;
    for i:=1 to length(s) do
     begin
       k:=1;
       for j:=i+1 to length(s) do
        if s[i]=s[j] then k:=k+1;
       if k>n then
        begin
          n:=k;
          c:=s[i];
        end;
     end;
    MaxNum:=n;
  end;

 function MaxStr(s:string):char;
  var
   i,j,k:integer;
   c:char;
   n:integer;
  begin
    n:=0;
    for i:=1 to length(s) do
     begin
       k:=1;
       for j:=i+1 to length(s) do
        if s[i]=s[j] then k:=k+1;
       if k>n then
        begin
          n:=k;
          c:=s[i];
        end;
     end;
    MaxStr:=c;
  end;

 procedure Inp;
  var
   t:text;
  begin
    assign (t,'freq.inp');
    reset (t);
    readln (t,n);
    b:=0;
    for i:=1 to n do
     begin
       readln (t,s);
       if MaxNum(s)>b then
        begin
          b:=MaxNum(s);
          c:=MaxStr(s);
        end;
     end;
    close (t);
  end;

 procedure Out;
  var
   t:text;
  begin
    assign (t,'freq.out');
    rewrite (t);
    writeln (t,c,' ',b);
    close (t);
  end;

  begin
    Inp;
    Out;
  end.