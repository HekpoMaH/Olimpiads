uses
  Math;
const
  cc = 200;
var
  n, a, b, c, x : int64;
  ans, ansa, ansb, ansc : int64;
begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  x := round(floor(sqrt(n / 6)));
  a := max(x - cc, 1);
  ans := 0;
  ansa := 0;
  ansb := 0;
  ansc := 0;
  while (a <= x + cc) do begin
    b := a;
    while (b <= x + cc) and (2 * (a * b + a + b) <= n) do begin
      c := b;
      while (c <= x + cc) do begin
        if (2 * (a * b + a * c + b * c) <= n) then begin
          if (a * b * c > ans) then begin
            ans := a * b * c;
            ansa := a;
            ansb := b;
            ansc := c;
          end;
        end else break;
        c := c + 1;
      end;
      b := b + 1;
    end;
    a := a + 1;
  end;
  writeln(ans);
  writeln(ansa, ' ', ansb, ' ', ansc);
end.