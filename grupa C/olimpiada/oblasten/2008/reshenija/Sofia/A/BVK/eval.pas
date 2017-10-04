program eval;


function fact(n: longword): longword;
begin
   if (n<=1) then fact := 1 else fact := n*fact(n-1);
end;

function get_variants(s: string): longword;
var i: integer;
var sc: byte;
var ps: byte;
var lc: integer;
var podizr: byte;
var podizr_v: array[0.. 255] of longword;
var s1: string;
begin
   sc := 0;
   lc := 0;
   podizr := 0;
   for i := 1 to length(s) do
   begin
      if (s[i]='(') then
      begin
         lc := lc+1;
         if (lc=1) then ps := i+1;
      end;
      if (s[i]=')') then
      begin
         lc := lc-1;
         if (lc=0) then
         begin
            sc := sc+1;
            s1 := copy(s, ps, i-ps);
            podizr_v[podizr] := get_variants(s1);
            podizr := podizr+1;
         end;
      end;
   end;
   get_variants := fact(sc);
   for i := 0 to podizr-1 do get_variants := get_variants*podizr_v[i];
end;

var c: longword;

var s: string;
begin
   readln(s);

   c := get_variants(s);
   writeln(c);
end.
