var a:array [1..100] of longint; k, n, t, i:longint;
begin
  readln (n);
  for i:=1 to n do
    begin
      read (t);
      inc(a[t]);
    end;
  k:=0;
  for i:=1 to 100 do k:=k+(a[i] div 4);
  writeln (k);
end.
