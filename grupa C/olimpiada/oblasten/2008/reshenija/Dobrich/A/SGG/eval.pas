program eval;
const fact : array[1..12] of longword = (1,2,6,24,120,720,5040,40320,362880,
 3628800, 39916800, 479001600);

var s : string;
    n : longword;

procedure count(s : string; var n : longword; lng : byte);
var i, j : byte;
    s1   : string;
    n1   : longword;

    plus, minus : byte;
    mult, divi  : byte;

begin
 {
 for j := 1 to lng do
  write(s[j]);
 writeln(' ',lng);
 }
 i := 1; n := 1;

 plus := 0; minus := 0;
 mult := 0; divi := 0;



 while i < lng do
 begin
  if s[i] = '(' then
   begin

    j := 1;
    while not(s[i+j] = ')') do
     begin
      s1[j] := s[i+j];
      j := j + 1;
     end;

    count(s1,n1,j-1);

    i := i + j + 1;
    n := n*n1;
    if s[i+1] = '(' then n := n*2;
   end;
  {
  for j := 1 to lng do
  write(s[j]);
  writeln(i,' OK!');
  }
  if s[i] = '+'
   then plus := plus + 1
   else if s[i] = '-'
         then minus := minus + 1
         else if s[i] = '*'
              then mult := mult + 1
              else if s[i] = '/'
                    then divi := divi + 1;
  if (plus > 0) then
   if (minus > 0)
    then
     begin
      n := n*fact[plus];
      plus := 0;
      minus := 0;
     end
    else if (mult > 0) or (divi > 0)
          then
           begin
            n := n*fact[plus-1];
            plus := 0;
            minus := 0;
           end
          else if i = lng - 1 then n := n*fact[plus];

  if (mult > 0) then
   if (divi > 0)
    then
     begin
      n := n*fact[mult];
      mult := 0;
      divi := 0;
     end
    else if (plus > 0) or (minus > 0)
          then
           begin
            n := n*fact[mult-1];
            mult := 0;
            divi := 0;
           end
          else if i = lng - 1 then n := n*fact[mult];

  i := i + 1;

 end;

end;

begin
readln(s);
count(s,n,length(s));
writeln(n);
end.
