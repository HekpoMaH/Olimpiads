uses
  testlib, SysUtils, Math;

const
  eps = 1e-9;

var
  jans, ja, jb, jc, n : int64;
  pans, pa, pb, pc : int64;

function readInt64(var ins : InStream) : int64;
var
  s : string;
  code : integer;
  res : int64;
begin
  s := ins.readWord(blanks, blanks);
  val(s, res, code);
  if (code <> 0) then begin
//    if (ins = inf) or (ins = ans) then 
//      quit(_fail, 'Expected int64 instead of "' + s + '"');
    quit(_pe, 'Ожидался int64 вместо "' + s + '"');
  end;
  result := res;
end;

begin
  jans := readInt64(ans);
  if (jans <= 0) then
    quit(_fail, IntToStr(jans) + ' found');
  n := readInt64(inf);
  ja := readInt64(ans);
  jb := readInt64(ans);
  jc := readInt64(ans);
  if (ja > maxLongInt) or (ja <= 0) then
    quit(_fail, IntToStr(ja) + ' found');
  if (jb > maxLongInt) or (jb <= 0) then
    quit(_fail, IntToStr(jb) + ' found');
  if (jc > maxLongInt) or (jc <= 0) then
    quit(_fail, IntToStr(jc) + ' found');
  if (jans <> ja * jb * jc) then
    quit(_fail, 'Jury answer has wrong volume');
  if (ja * jb > n) or (jb * jc > n) or (ja * jc > n) then
    quit(_fail, 'Jury answer has too big square');
  if (2 * (ja * jb + jb * jc + ja * jc) > n) then
    quit(_fail, 'Jury answer has too big square');

  pans := readInt64(ouf);
  pa := readInt64(ouf);
  pb := readInt64(ouf);
  pc := readInt64(ouf);
  if (pans <= 0) then
    quit(_wa, 'Неположительный объем: ' + IntToStr(pans));
  if (pa <= 0) then
    quit(_wa, 'Неположительная длина первой стороны: ' + IntToStr(pa));
  if (pb <= 0) then
    quit(_wa, 'Неположительная длина второй стороны: ' + IntToStr(pb));
  if (pc <= 0) then
    quit(_wa, 'Неположительная длина третей стороны: ' + IntToStr(pc));


  if (pa > maxLongInt) then
    quit(_wa, 'Слишком длинная первая сторона: ' + IntToStr(pa));
  if (pb > maxLongInt) then
    quit(_wa, 'Слишком длинная вторая сторона: ' + IntToStr(pb));
  if (pc > maxLongInt) then
    quit(_wa, 'Слишком длинная третья сторона: ' + IntToStr(pc));

  if (pa * pb > n) or (pa * pc > n) or (pb * pc > n) then
    quit(_wa, 'Слишком большая площадь: ' + IntToStr(2 * (pa * pb + pa * pc + pb * pc)));
  if (abs(pans - 1.0 * pa * pb * pc) > eps) or (pans <> pa * pb * pc) then
    quit(_wa, 'Неправильно посчитан объем коробки. Выведен: ' + IntToStr(pans) + ', получается: ' + IntToStr(pa * pb * pc));
  if (2 * (pa * pb + pa * pc + pb * pc) > n) then
    quit(_wa, 'Слишком большая площадь: ' + IntToStr(2 * (pa * pb + pa * pc + pb * pc)));

  if (jans < pans) then
    quit(_fail, 'Участник нашел решение лучше');
  if (jans > pans) then
    quit(_wa, 'Недостаточно большой объем, ожидалось: ' + IntToStr(jans) + ', получено: ' + IntToStr(pans));

  quit(_ok, 'OK. Объем равен: ' + IntToStr(pans));

end.