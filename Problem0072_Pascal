var n, k, t, v, x, y, temp, count, hx, hy:longint; s:real; rez:string;
begin
  readln (n, k, t, v);
  readln (hx, hy);
  count:=0; x:=0; y:=0; temp:=1;
  x:=x+temp; y:=y+temp;
  while count<k do
    begin
      if count=k then break;
      temp:=temp+n;
      x:=x+temp; y:=y-temp;
      inc(count);
      if count=k then break;
      temp:=temp+n;
      x:=x-temp; y:=y-temp;
      inc(count);
      if count=k then break;
      temp:=temp+n;
      x:=x-temp; y:=y+temp;
      inc(count);
      if count=k then break;
      temp:=temp+n;
      x:=x+temp; y:=y+temp;
      inc(count);
      if count=k then break;
    end;
  if sqrt(sqr(x-hx)+sqr(y-hy))<=t*v*sqrt(2) then rez:='Good night Ia' else rez:='Poor Ia';
  writeln (rez);
end.
