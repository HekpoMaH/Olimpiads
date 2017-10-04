var
  ansa, ansb, ansc, a, b, c, n, max_b : integer;
  ans : int64;

  function min(a, b : integer) : integer;
  begin
    if (a < b) then
      Result := a
    else
      Result := b;
  end;

begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  n := n div 2;
  ans := 0;
  ansa := 0;
  ansb := 0;
  ansc := 0;
  for a := 1 to trunc(sqrt(n / 3) + 0.5) do begin
    max_b := trunc(sqrt((a * a + n))) - a;
    for b := 1 to min(max_b, (n - a) div (a + 1)) do begin
      c := (n - a * b) div (a + b);
      if (ans < int64(a) * b * c) then begin
        ans := int64(a) * b * c;
        ansa := a;
        ansb := b;
        ansc := c;
      end;
    end;
  end;
  writeln(ans);
  writeln(ansa, ' ', ansb, ' ', ansc);
end.                            