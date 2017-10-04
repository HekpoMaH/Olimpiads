{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+}
{$M 16384,0,655360}
{$N+}
Const MaxN = 50;
Type TNum = Comp;
  Var cv, cb: array[1..MaxN] of longint;
      N: integer;

      cnt: Array[1..MaxN, 0..MaxN] of TNum;

procedure readdata;
  var i: integer;
begin
  read(N);
  for i := 1 to N do read(cv[i], cb[i]);

  fillchar(cnt, sizeof(cnt), 0);
end;

function getdo(p: integer): integer;
  var r: real;
      t, t1: integer;
      s: string;
begin
  r := cb[p] / cv[p];
  str(r*1000:0:0, s);
  val(s, t, t1);
  getdo := t;
end;

function poss(k, p: integer): boolean;
begin
  poss := (cv[p] > cv[k]) and (getdo(p) < getdo(k));
end;

procedure solve;
  var i, j, k: integer;
      res: TNum;
begin
  fillchar(cnt, sizeof(cnt), 0);

  for i := 1 to N do begin
    cnt[i, 1] := 1;

    for j := 1 to i - 1 do
    if poss(j, i) then
      for k := 1 to j do
        cnt[i, k + 1] := cnt[i, k + 1] + cnt[j, k];
  end;

  for k := N downto 1 do begin
    res := 0;
    for i := 1 to N do res := res + cnt[i, k];

    if res <> 0 then begin
      writeln(k);
      writeln(res:0:0);
      exit;
    end;
  end;

end;

BEGIN
  assign(input, 'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);
    readdata;
    solve;
  close(input); close(output);
END.