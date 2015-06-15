var a:array[1..1000] of longint; n, m, rez, k, i, j:longint;

procedure out;
begin
  writeln (rez); halt;
end;

begin
  readln (n, m);
  for i:=1 to n do read (a[i]);
  for i:=1000 downto 1 do
    begin
      k:=0;
      for j:=1 to n do k:=k+(a[j] div i);
      if k>=m then begin rez:=i; out; end
    end;
end.
