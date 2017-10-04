var
  n, m: LongInt;
  i, j, t: LongInt;
  br: Int64;
  fl: Boolean;

function Prime(m: Int64) : Boolean;
var
  k: LongInt;

begin
  Prime:= true;
  for k:= 2 to (m div 2) do
    if m mod k = 0 then
    begin
      Prime:= false;
      break;
    end;
end;

begin
  readln(n);
  br:= 0;

  for i:= 2 to n div 2 do
    if Prime(i) then
    begin
      for j:= (n div i) - 1 downto 1 do
      begin
        t:= n - j*i;
        if Prime(t) then
          br:= br+1;
      end;
    end;

  m:= n + 1;
  repeat
    if Prime(m) then
      fl:= true
    else
      m:= m+1;
  until fl = true;

  writeln(br mod m);
end.
