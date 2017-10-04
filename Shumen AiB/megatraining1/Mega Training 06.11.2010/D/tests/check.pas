program check_b;

uses
  testlib, symbols;

var
  j, p: longint;

begin
  j := ans.readlongint;
  p := ouf.readlongint;

  if j <> p then
    quit(_wa, 'expected: ' + str(j, 0) + ', found: ' + str(p, 0));
  quit(_ok, '');
end.
