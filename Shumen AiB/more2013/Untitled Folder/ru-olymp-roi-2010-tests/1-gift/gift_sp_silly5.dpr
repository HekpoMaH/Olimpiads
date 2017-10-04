var
  n : integer;
  c, ansa, ansb, ansc, ans : int64;
  a, b : integer;
begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  n := n div 2;
  ans := 0;
  ansa := 0;
  ansb := 0;
  ansc := 0;
  for a := 1 to n do begin
    for b := 1 to n do begin
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
  writeln(ans);
  writeln(ansa, ' ', ansb, ' ', ansc);
end.