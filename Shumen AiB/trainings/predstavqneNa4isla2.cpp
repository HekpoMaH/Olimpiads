
{$apptype console}
{$q+,r+,n-,o+}

const cinfile = 'c.in';
      coutfile = 'c.out';

const nmax = 10011;
      inf = maxlongint shr 1;

type int = longint;

var n, k : int;
    strong, weak : array[1..nmax] of int;
    s_strong, s_weak : array[1..nmax] of string;

procedure solve;
var i, j, t : int;
begin
   for i:=1 to k do begin
      str(i, s_strong[i]);
      strong[i]:=length(s_strong[i]);
      weak[i]:=strong[i];
      s_weak[i]:=s_strong[i];
   end;
   for i:=k + 1 to n do begin
      strong[i]:=inf;
      weak[i]:=inf;
      for j:=1 to i shr 1 do begin
         if weak[i] > weak[i - j] + 1 + weak[j] then begin
            weak[i]:=weak[i - j] + 1 + weak[j];
            s_weak[i]:=s_weak[i - j] + '+' + s_weak[j];
         end;
      end;

      for j:=1 to i do
         if sqr(j) > i then break else begin
            t:=i div j;
            if (j > 1) and (i = t * j) then begin
               if strong[i] > strong[t] + 1 + strong[j] then begin
                  strong[i]:=strong[t] + 1 + strong[j];
                  s_strong[i]:=s_strong[t] + '*' + s_strong[j];
               end;
            end;
         end;

      if strong[i] < weak[i] then begin
         weak[i]:=strong[i];
         s_weak[i]:=s_strong[i];
      end else
         if weak[i] + 2 < strong[i] then begin
            strong[i]:=weak[i] + 2;
            s_strong[i]:='(' + s_weak[i] + ')';
         end;
   end;
end;

begin
   assign(input, cinfile); reset(input);
   assign(output, coutfile); rewrite(output);
   fillchar(strong, sizeof(strong), 0);
   fillchar(weak, sizeof(weak), 0);
   read(n, k);
   solve;
   write(s_weak[n]);
   close(input); close(output);
end.
