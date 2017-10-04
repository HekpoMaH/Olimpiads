var a, b, c, x, y : uint64;

begin
   assign(input, 'plusxor.dat'); reset(input);
   assign(output, 'plusxor.sol'); rewrite(output);

   readln(a,b);

   c := (a xor b) shr 1;
   x := c and not b;
   y := b or c;

   if (x + y <> a) or (x xor y <> b) then writeln(-1)
   else writeln(x, ' ', y);
   
   close(input);close(output);
end.