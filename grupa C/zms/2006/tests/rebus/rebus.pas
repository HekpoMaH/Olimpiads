{$H+}

Uses SysUtils;

Type
    TNumber = record
        sign : integer;
        digits : string;
    End;

Var
    FIn,FOut : Text;
    numbers : array [1..64] of TNumber;
    N : integer;
    canBeZero : array ['A'..'Z'] of boolean;
    values : array ['A'..'Z'] of integer;
    used : array [0..9] of boolean;
    maxLength : integer;

Procedure ReadInput;
Var
    rebus : string;
    sign : integer;
    currentSign : integer;
    i : integer;

Begin
    assign(FIn,''); reset(FIn);
    readln(FIn,rebus);
    close(FIn);
    rebus := rebus + '+';
    sign := 1;
    currentSign := 1;
    N := 1;
    numbers[1].sign := 1;
    numbers[1].digits := '';


    for i := 1 to length(rebus) do
    begin
        if rebus[i] in ['A'..'Z'] then begin
            numbers[N].digits := rebus[i] + numbers[N].digits;
        end
        else begin
            if rebus[i] = '=' then begin
                sign := -1;
                currentSign := -1;
            end
            else if rebus[i] in ['-','+'] then begin
                if rebus[i] = '-' then
                    currentSign := -1 * sign
                else
                    currentSign := sign;
            end;

            if rebus[i-1] <> '=' then begin
                inc(N);
                numbers[N].sign := currentSign;
                numbers[N].digits := '';
            end;
        end;
    end;
    dec(N);
End;

Procedure Init;
Var
    i : integer;
    c : char;
Begin
    fillchar(used,sizeof(used),0);
    fillchar(canBeZero,sizeof(canBeZero),true);

    for i := 1 to N do
    begin
        canBeZero[ numbers[i].digits[ length(numbers[i].digits) ] ] := false;
        if length(numbers[i].digits) > maxLength then
            maxLength := length(numbers[i].digits);
    end;

    for c := 'A' to 'Z' do
    begin
        values[c] := -1;
    end;
End;

Function BackTrack(letterIndex,numberIndex,sum : integer) : boolean;
Var
    num : TNumber;
    c : char;
    dig : integer;
    result : boolean;

Begin
    if letterIndex > maxLength then begin
        BackTrack := sum = 0;
        exit;
    end;

    if numberIndex > N then begin
        if sum mod 10 = 0 then
            BackTrack := BackTrack(letterIndex+1,1,sum div 10)
        else
            BackTrack := false;
        exit;
    end;

    num := numbers[numberIndex];

    if length(num.digits) < letterIndex then
    begin
        BackTrack := BackTrack(letterIndex,numberIndex + 1, sum);
        exit;
    end;

    c := num.digits[letterIndex];
    if values[c] <> -1 then begin
        BackTrack := BackTrack(letterIndex,numberIndex + 1, sum + values[c] * num.sign);
        exit;
    end
    else begin
        for dig := 0 to 9 do begin
            if not used[dig] then begin
                if (dig = 0) and (not canBeZero[c]) then
                    continue;

                used[dig] := true;
                values[c] := dig;
                result := BackTrack(letterIndex,numberIndex + 1,sum + dig * num.sign);
                if result then begin
                    BackTrack := true;
                    exit;
                end;
                used[dig] := false;
                values[c] := -1;
            end;
        end;
    end;
    BackTrack := false;
End;

Procedure WriteOutput;
Var
    c : char;
Begin

    assign(FOut,'');
    rewrite(FOut);

    for c := 'A' to 'Z' do
        if values[c] <> -1 then
            writeln(FOut,c,'=',values[c]);
    close(FOut);
End;

Begin
    ReadInput;
    Init;

    if BackTrack(1,1,0) then
        WriteOutput
    else
        writeln('NOPE');
End.
