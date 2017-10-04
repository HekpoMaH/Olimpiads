Program eva1;
Uses CRT;
type tree=^element;
           element = record
                      data: char;
                      left,right:tree;
                     end;
type mnojestvo = set of char;
     stack=^element;
     element = record
               data: char;
               next: stack;
     end;
var top: stack; root:tree; M: mnojestvo; S: string; brs, br, i:byte; OK: boolean;

function IfEmptyStack(var top: stack): boolean;
begin
     IfEmptyStack:=top=nil;
end;

procedure Push(var top:stack; c: char);
var p:stack;
begin
     new(p);
     p^.data:=c;
     p^.next:=top;
     top:=p;
end;

procedure Pop(var top: stack; var c: char);
var p:stack;
begin
     p:=top;
     c:=p^.data;
     top:=p^.next;
     dispose(p);
end;

procedure InitTree(var root:tree);
begin
     root:=nil;
end;

function IsEmptyTree(var root:tree):boolean;
begin
     IsEmptyTree:=(root=nil);
end;

begin
ClrScr;
  OK:=true;
  br:=0;
  brs:=0;
  M:=['a'..'z','+','-','*','/','^','(',')'];
       repeat
       write('Vyvedi izraza: ');
       readln(S);
       until (length(S)<25);
       for i:=1 to length(S) do
       begin
            if not (S[i] in M) then OK:=false;
            brs:=brs+1;
       end;
       if OK=false then writeln('Izraza trqbva da sydyrja samo: malki latinski bukvi, +, -, *, /, ^, (, ) ')
       else

       for i:=1 to brs do
       begin
           Push(top,S[i]);
       end;

readln;
end.