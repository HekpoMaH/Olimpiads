uses
  testlib, Math, SysUtils;

const
  numzones = 5;
  maxsize = numzones;
  maxn = 200000;
  ccost : array[1..11] of longint = (10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);

var
  pcost, plen, i, curzone, realans, newzone, jcost, j, k : longint;
  pans : array[1..maxsize] of string;
  n : array[1..numzones] of longint;
  s : array[1..numzones, 1..maxn] of string;
  petya, vasya : string;

function cost(s1, s2 : string) : longint;
var
  i : longint;
begin
  for i := 1 to length(s1) do begin
    if (s1[i] <> s2[i]) then begin
      result := ccost[i];
      exit;
    end;
  end;
  result := ccost[11];
end;


begin
  pcost := ouf.readlongint;
  plen := ouf.readlongint;
  if (plen > maxsize) then
    quit(_wa, 'Слишком большая последовательность звонков, ее длина: ' + IntToStr(plen));
  for i := 1 to plen do begin
    pans[i] := ouf.readword(blanks, blanks);
    if (length(pans[i]) <> 10) then
      quit(_wa, 'Неправильная длина номера: ' + pans[i]);
  end;

  petya := inf.readword(blanks, blanks);
  vasya := inf.readword(blanks, blanks);
  for i := 1 to 5 do begin
    n[i] := inf.readlongint;
    for j := 1 to n[i] do begin
      s[i][j] := inf.readword(blanks, blanks);
    end;
  end;
  if (petya <> pans[1]) then
    quit(_wa, 'Первый номер - не Петин');
  if (vasya <> pans[plen]) then
    quit(_wa, 'Последний номер - не Васин');
  curzone := 1;
  realans := 0;
  for i := 2 to plen - 1 do begin
    if pans[i] = pans[i - 1] then
      quit(_wa, 'Звонок с номера: ' + pans[i] + ' самому себе');
    realans := realans + cost(pans[i - 1], pans[i]);
    newzone := 0;
    for j := curzone - 1 to curzone + 1 do begin
      if (j < 1) or (j > 5) then continue;
      for k := 1 to n[j] do begin
        if s[j][k] = pans[i] then begin
          newzone := j;
          break;
        end;
      end;
      if (newzone <> 0) then break;
    end;
    if (newzone = 0) then
      quit(_wa, 'С номера ' + pans[i - 1] + ' нельзя позвонить на номер ' + pans[i]);
    curzone := newzone;
  end;
  realans := realans + cost(pans[plen - 1], pans[plen]);
  if (curzone <> 4) and (curzone <> 5) then
    quit(_wa, 'С номера ' + pans[plen - 1] + ' нельзя позвонить на номер ' + pans[plen]);
  if (realans <> pcost) then
    quit(_wa, 'Правильная стоимость таких звонков: ' + IntToStr(realans) + ', а выведена: ' + IntToStr(pcost));
  jcost := ans.readlongint;
  if (pcost < jcost) then
    quit(_fail, 'Участник нашел решение лучше жюри');
  if (jcost < pcost) then
    quit(_wa, 'Слишком дорогие звонки: ' + IntToStr(pcost) + ', а возможно за: ' + IntToStr(jcost));
  quit(_ok, 'ОК. Стоимость звонков: ' + IntToStr(pcost));
end.
