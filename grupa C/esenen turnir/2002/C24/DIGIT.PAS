Var K:Longint;
    s,s1:String;
Begin
 Repeat
  Write('Enter K ');
  ReadLn(K);
 Until K<100000000;
  Write('Vuvedete cifrite ');
  ReadLn(s);
  s1:=Copy(s,K,1);
  Writeln(s1);
  ReadLn;
End.
