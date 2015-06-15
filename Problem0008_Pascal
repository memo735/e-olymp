var n, max, s, m, k, i, j:longint;
begin
  readln (n);
  if trunc(sqrt(n))<>sqrt(n) then 
    begin
      m:=trunc(sqrt(n))+1;
      s:=4+(m-2)*2*3+(m-2)*(m-2)*2;
    end
  else
    begin
      m:=trunc(sqrt(n));
      s:=4+(m-1)*3*2+(m-1)*(m-1)*2;
      writeln (s); halt;
    end;
  max:=n-(m-1)*(m-1); k:=1; s:=s+3;
  for i:=2 to m-1 do
    begin
      if k=max then begin writeln (s); halt; end;
      s:=s+2;
      inc(k);
    end;
  if k=max then begin writeln (s); halt; end;
  s:=s+3; inc(k);
  for i:=2 to m do
    begin
      if k=max then begin writeln (s); halt; end;
      s:=s+2; inc(k);
    end;
  writeln (s);
end.
