var
  ansa, ansb, ansc, ans, a, b, c, n : integer;

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
    for b := 1 to (n - a) div (a + 1) do begin
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