var
  n : integer;
  c, ansa, ansb, ansc, ans : double;
  maxa, a, b : integer;
begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  n := n div 2;
  ans := 0;
  ansa := 0;
  ansb := 0;
  ansc := 0;
  maxa := round(sqrt(n));
  for a := 1 to maxa do begin
    for b := 1 to a do begin
      if (a * b + a + b > n) then break;
      c := (n - a * b) div (a + b);
      if (ans < a * b * c) then begin
        ans := a * b * c;
        ansa := a;
        ansb := b;
        ansc := c;
      end;
    end;
  end;
  writeln(ans:0:0);
  writeln(ansa:0:0, ' ', ansb:0:0, ' ', ansc:0:0);
end.