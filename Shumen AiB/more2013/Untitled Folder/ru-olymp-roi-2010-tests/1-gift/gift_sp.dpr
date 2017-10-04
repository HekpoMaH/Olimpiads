uses
  Math;
var
  a, b, c, aa, n, ans, ansa, ansb, ansc : int64;
  bb, cc : extended;

begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  assert((6 <= n) and (n <= 1e13));
  n := n div 2;
  aa := round(floor(sqrt(n / 3)));
  ans := aa * aa * aa;
  ansa := aa;
  ansb := aa;
  ansc := aa;
  a := aa + 1;
  repeat
    a := a - 1;
    bb := sqrt(1.0 * a * a + n) - a;
    b := round(floor(bb)) + 1;
    repeat
      b := b - 1;
      cc := (n - a * b) / (a + b);
      c := round(floor(cc));
      if (a * b * c > ans) then begin
        ans := a * b * c;
        ansa := a;
        ansb := b;
        ansc := c;
      end;
    until a * b * cc < ans;
  until a * bb * bb < ans;
  writeln(ans);
  writeln(ansa, ' ', ansb, ' ', ansc);
end.