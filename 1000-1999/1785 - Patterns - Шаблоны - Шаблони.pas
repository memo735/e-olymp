var p1, p2 : string[10];
  s : array[1..2, 0..9] of boolean;
  n, i, j, k, answer, nowans : longint;// определение подходящих цифр

procedure fill(c : char; num : longint);
var pj, st, len : longint;
begin
  // пока никакие цифры не подходят
  for pj := 0 to 9 do s[num, pj] := false;
  // была цифра
  if (c in ['0'..'9']) then
  begin
  // определяем, что за цифра
    st := ord(c) - ord('0');
    len := 0; // и за ней никого размечать не будем буква
  end
  else
    if (c in ['a'..'g']) then
    begin
      // определяем номер по алфавиту
      st := ord(c) - ord('a');
      // и 3 следующих за ней тоже допустимы
      len := 3 // вопросительный знак
    end
    else
      if (c = '?') then
      begin
        st := 0; // начиная с нуля
        len := 9 // и оставшиеся 9 цифр за ней
      end
      else st := -1; // а вдруг что-то другое?
      // если что-то другое — то ничего не делаем
  if (st <> -1) then
  // расставляем true
  for pj := st to st+len do s[num, pj] := true
end;

begin
  answer := 1; // будем накапливать ответ тут
  readln(p1); readln(p2); // считали строки
  // посчитали длину — она совпадает
  n := length(p1);
  // идем по всем позициям
  for i := 1 to n do
  begin
  fill(p1[i], 1); // заполняем первый массив
  fill(p2[i], 2); // и второй
  // на данной позиции пока может стоять 0 цифр
  nowans := 0;
  for j := 0 to 9 do // идем по цифрам
    if (s[1, j] = true) and (s[2, j] = true) then
    // подходит, увеличиваем на 1 число подходящих
    inc(nowans);
    // и умножаем на это ответ
    answer := answer * nowans
  end;
  writeln(answer)
end.
