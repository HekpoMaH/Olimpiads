{$A+,B-,D+,E+,F-,G+,I+,L+,N+,O-,P+,Q+,R+,S+,T-,V-,X+,Y+}
{$M 10000,0,100360}

program gen_tests;

uses
  dos, symbols;

var
  j, m, n: longint;
  s: string;

begin
  assign(input, 'alltests');
  reset(input);
  j := 0;
  while not seekeof do
  begin
    inc(j);
    read(m, n);
    s := str(j div 10, 0) + str(j mod 10, 0);
    assign(output, s);
    rewrite(output);
    writeln(m, ' ', n);
    close(output);
    exec('c:\command.com', '/c copy ' + s + ' input.txt');
    exec('..\b.exe', '');
    exec('c:\command.com', '/c copy output.txt ' + s + '.a');
  end;
end.