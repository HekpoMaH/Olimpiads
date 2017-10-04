program groups;

var n, p: word;
var a: array [0.. 499] of extended;
var inited: boolean;
var min_ed: extended;

var d: array [0.. 499] of extended;
var d_sum: extended;
procedure make_groups(b, g, l, pos: word); //l - nivo, pos - poredno a
var i, i1: integer;
var s: extended;
begin
   if l = p-1 then
   begin
      s := 0;
      for i := pos to n-1 do s := s+a[i];
      s := s/(n-pos);
      d[l] := 0;
      for i := pos to n-1 do d[l] := d[l] + sqr(a[i]-s);
      d_sum := d_sum+d[l];
      if (not inited) or (d_sum < min_ed) then
      begin
         inited := true;
         min_ed := d_sum;
      end;
      d_sum := d_sum-d[l];
   end else begin
      s := 0;
      for i := 0 to b-g-1 do
      begin
         s := s + a[pos+i];
         d[l] := 0;
         for i1 := 0 to i do d[l] := d[l] + sqr(a[pos+i1]-s/(i+1));
         d_sum := d_sum + d[l];
         if (not inited) or (d_sum<min_ed) then make_groups(b-(i+1), g-1, l+1, pos+i+1);
         d_sum := d_sum - d[l];
      end;
   end;
end;

var i: integer;
begin
   readln(n, p);
   for i := 0 to n-1 do read(a[i]);

   inited := false;
   d_sum := 0;

   make_groups(n, p, 0, 0);

   writeln(min_ed:0:4);
end.
