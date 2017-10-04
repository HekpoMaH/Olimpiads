{$A+,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O+,P+,Q+,R+,S+,T-,U-,V+,W-,X+,Y+,Z1}
{$APPTYPE CONSOLE}

//uses SysUtils, Classes;

const
  MaxN = 1000000;
  MaxM = 1000000;

var
  n, m, k, x, y, l, r, t, i : integer;
  head, last : array[1 .. MaxN] of integer;
  dest, next : array[1 .. 2 * MaxM] of integer;
  queue : array[1 .. MaxN + 10] of integer;
  time : array[1 .. MaxN] of integer;

procedure addedge(x, y, m: integer);
begin
  dest[m] := y;
  next[m] := 0;
  if head[x] = 0 then begin
     head[x] := m;
     last[x] := m;
  end else begin
     next[last[x]] := m;
     last[x] := m;
  end
end;

begin
  reset(input, 'g.in');
  rewrite(output, 'g.out');
  read(n);
  for i := 1 to n do
    time[i] := maxint;
  l := 1;
  r := 1;
  read(k);
  for i := 1 to k do begin
    read(queue[r]);
    time[queue[r]] := 0;
    inc(r);
  end;
  fillchar(head, sizeof(head), 0);
  read(m);
  for i := 1 to m do begin
    read(x, y);
    addedge(x, y, 2 * i - 1);
    addedge(y, x, 2 * i);
  end;
  repeat
    t := head[queue[l]];
    while (t <> 0) do begin
      if time[dest[t]] > time[queue[l]] + 1 then begin
        time[dest[t]] := time[queue[l]] + 1;
        queue[r] := dest[t];
        inc(r);
      end;
      t := next[t];
    end;
    inc(l);
  until l >= r;
  for i := 1 to n do begin
    if time[i] = maxint then 
      writeln('BOTVA');
    write(time[i], ' ');
  end;
  writeln;  
  close(input);close(output)
end.
