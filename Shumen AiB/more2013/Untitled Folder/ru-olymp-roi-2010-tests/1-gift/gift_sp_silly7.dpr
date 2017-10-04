var
  ansa, ansb, ansc, ans, a, b, c, n : integer;
begin
  reset(input, 'gift.in');
  rewrite(output, 'gift.out');
  read(n);
  ans := 0;
  ansa := 0;
  ansb := 0;
  ansc := 0;
  for a := 1 to n do begin
    for b := 1 to (n div 2 - a) div (a + 1) do begin
      c := (n div 2 - a * b) div (a + b);
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