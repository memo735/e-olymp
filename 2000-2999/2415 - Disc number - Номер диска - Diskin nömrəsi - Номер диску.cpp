var n, cavab: QWord;
begin
  readln(n);
  cavab:=0;
  while (n mod 2 = 0) do
  begin
    n:=n div 2;
    cavab:=cavab+1;
  end;
  writeln(cavab);
end.
