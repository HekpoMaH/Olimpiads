uses
  Math;
var
  n, a : int64;
begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  a := round(floor(sqrt(n / 6)));
  writeln(a * a * a);
  writeln(a, ' ', a, ' ', a);
end.