const maxN = 100000;

function solve(const x : array of longint; n : longint) : int64;
var i             : longint;
   ans, sum, sum2 : int64;
begin
   ans := 0;
   sum := 0;
   sum2 := 0;
   for i:= 0 to n-1 do begin
      ans := ans + int64(i) * x[i] * x[i] - 2 * x[i] * sum + sum2;
      sum := sum + x[i];
      sum2 := sum2 + x[i] * x[i];
   end;
   solve := ans;
end; { solve }

var
   n, i     : longint;
   x, y     : array [1..maxN] of longint;
   ifs, ofs : Text;

begin
   assign(ifs, 'points.dat'); reset(ifs);
   assign(ofs, 'points.sol'); rewrite(ofs);

   readln(ifs, n);
   for i := 1 to n do readln(ifs, x[i], y[i]);

   writeln(ofs, solve(x, n) + solve(y, n));
   
   close(ifs);
   close(ofs);
end.  