program Problem136;
var x1,x2,y1,y2,k:int64;
{Беру int64, поскольку количество точек может и не вмещатся в longint}

function NOD(q,w:int64):int64; {функция, которая реализует поиска НОД двух чисел по алгоритму Евклида}
begin
  while q<>w do if q>w then q:=q-w else w:=w-q;
  NOD:=q;
end;

begin
  readln(x1,y1,x2,y2);
  if (x1=x2) or (y1=y2) then k:=abs(x1-x2)+abs(y1-y2)+1 {здесь совмещены 3 случая: одинаковая абсцисса, одинаковая ордината, точки совпадают}
  else
    if (y1*(x2-x1)-x1*(y2-y1)<>0) then k:=NOD(abs(y2-y1),NOD(abs(x1-x2),abs(y1*(x2-x1)-x1*(y2-y1))))+1 {воспользовались свойством НОД(a,b,c)=НОД(a,НОД(b,c))}
    else k:=NOD(abs(y2-y1),abs(x1-x2))+1;
  writeln(k);
end.
