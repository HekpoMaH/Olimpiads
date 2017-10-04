var
  ansa, ansb, ansc, ans, a, b, c, n : integer;
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
      for c := 1 to n do begin
        if ((a * b + b * c + a * c) <= n) then begin
          if (ans < a * b * c) then begin
            ans := a * b * c;
            ansa := a;
            ansb := b;
            ansc := c;
          end;
        end;
      end;
    end;
  end;
  writeln(ans);
  writeln(ansa, ' ', ansb, ' ', ansc);
end.