Program Groups;

const MaxReal = 1000000000;

type
  Masiv= array[1..500] of Real;
  Matrix= array[1..500,1..500] of Real;

var
  a: Masiv;
  f, g: Matrix;
  n, k: Integer;
  i, j, t: Integer;
  min: Real;

procedure CalcG;
var
  p, q, m, c: Integer;
  d, s: Real;

begin
  for p:= 1 to n do
    for q:= 1 to n-p+1 do
    begin
      m:= p+q-1;
      s:= 0;
      for c:= p to m do
        s:= s + a[c];
      s:= s/q;
      d:= 0;
      for c:= p to m do
        d:= d + sqr(a[c] - s);
      g[p,q]:= d;
    end;
end;

begin
  readln(n, k);
  for i:= 1 to n do
    read(a[i]);
  CalcG;


  for i:= 1 to n do
    f[i,1]:= g[1,i];

  for i:= 2 to n do
    for j:= 2 to k do
      if j <= i then
      begin
        min:= MaxReal;
        for t := 1 to i-j+1 do
          if f[i-t,j-1] + g[i-t+1,t] < min then
            min:= f[i-t,j-1] + g[i-t+1,t];
        f[i,j]:= min;
      end;

  writeln(f[n,k]:1:4);
end.

