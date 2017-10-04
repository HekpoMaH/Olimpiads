program primes;

var p_count: word;
var p: array [0.. 49999] of word;
var n: word;
var s: qword;

procedure get_next_prime();
var i: integer;
var k: longword;
var f: boolean;
begin
   k := p[p_count-1];
   while true do
   begin
      k := k+2;
      f := false;
      for i := 1 to p_count-1 do
      begin
         if (k mod p[i]) = 0 then
         begin
            f := true;
            break;
         end;
      end;
      if (not f) then
      begin
         p[p_count] := k;
         p_count := p_count+1;
         break;
      end;
   end;
end;

procedure get_s(min_p, sum: word);
var i: integer;
begin
   i := min_p;
   while (sum+p[i]<=n) and (p[i]<>n) do
   begin
      if sum+p[i] = n then s := s+1
         else get_s(i, sum+p[i]);
      i := i+1;
   end;
end;

begin
   p_count := 2;
   p[0] := 2;
   p[1] := 3;

   s := 0;

   readln(n);

   while (p[p_count-1]<=n) do get_next_prime();
   get_s(0, 0);
   writeln(s mod p[p_count-1]);
end.
