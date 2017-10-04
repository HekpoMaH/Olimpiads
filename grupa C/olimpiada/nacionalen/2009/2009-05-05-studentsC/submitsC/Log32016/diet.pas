{
TASK:DIET
LANG:PASCAL
}

program diet;
var one,two,three,gr,days,cut:longint;
begin
{  assign(input,'diet.in'); reset(input);
  assign(output,'diet.out'); rewrite(output);}
  readln(one,two,three);
  gr:=one+two*2+three*3;
  days:=gr div 6;
  one:=one-days;
  two:=two-days;
  three:=three-days;
  while three<0 do
    begin
      one:=one-1;
      two:=two-1;
      three:=three+1;
    end;
  while two<0 do
    begin
      while (two<0) and (one>1) do
        begin
          one:=one-2;
          two:=two+1;
        end;
      while (two<0) and (three>0) do
        begin
          one:=one+1;
          cut:=cut+1;
          two:=two+1;
          three:=three-1;
          while (two<0) and (one>1) do
            begin
              one:=one-2;
              two:=two+1;
            end;
        end;
      if two<0 then
        begin
          one:=one-2;
          two:=two+1;
        end;
    end;
  while one<0 do
    begin
      while (one<0) and (two>0) do
        begin
          cut:=cut+1;
          one:=one+2;
          two:=two-1;
        end;
      if one<0 then
        begin
          one:=one+1;
          cut:=cut+1;
          two:=two+1;
          three:=three-1;
        end;
    end;
  while two<0 do
    begin
      cut:=cut+1;
      three:=three-1;
      one:=one+1;
      two:=two+1;
    end;
  writeln(days,' ',cut);
{  close(input);
  close(output); }
end.