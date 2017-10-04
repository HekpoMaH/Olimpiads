uses
  Math;
const
  cc = 2000;
var
  c, ans, ansa, ansb, ansc : int64;
  n, ab, x, a, b : int64;
begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  n := n div 2;
  x := round(floor(sqrt(n / 3)));
  a := max(x - cc, 1);
  ans := 0;
  ansa := 0;
  ansb := 0;
  ansc := 0;
  while (a <= x) do begin
    b := x;
    ab := a * b;
    while (b <= x + cc) do begin
      if ((ab + a + b) > n) then break;
      c := (n - ab) div ((a + b));
      if (ab * c > ans) then begin
        ans := ab * c;
        ansa := a;
        ansb := b;
        ansc := c;
      end;
      ab := ab + a;
      b := b + 1;
    end;
    a := a + 1;
  end;
  writeln(ans);
  writeln(ansa, ' ', ansb, ' ', ansc);
end.