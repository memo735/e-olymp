type tLong = array[0..100] of byte;
var i, t, l{ength}, b{usy}, f{ree}, n{umber} : LongInt;
    prv, cur : array[0..200] of tLong;

procedure addLong(var a: tLong; b, c: tLong);
var i, m: LongInt;
begin
  if b[0] > c[0] then m := b[0] else m := c[0];
  fillchar(a, sizeof(a), 0);
  for i := 1 to m do
  begin
    a[i + 1] := (a[i] + b[i] + c[i]) div 10;
    a[i] := (a[i] + b[i] + c[i]) mod 10;
  end;
  if a[m + 1] <> 0 then a[0] := m + 1 else a[0] := m;
end;

procedure setLong(var a: tLong; n: LongInt);
begin
  fillchar(a, sizeof(a), 0);
  a[0] := 1;
  a[1] := n;
end;

procedure c_n_k(n, k: LongInt);
var i, j: LongInt;
begin
  fillchar(prv, sizeof(prv), 0);
  setLong(prv[0], 1);
  for i := 1 to n do
  begin
    setLong(cur[0], 1);
    for j := 1 to k do addLong(cur[j], prv[j], prv[j - 1]);
    prv := cur;
  end;
  for i := cur[k][0] downto 1 do write(cur[k][i]);
  writeln;
end;

begin
  b := 0; read(l); read(n);
  for i := 1 to n - 1 do begin read(t); b := b + t + 1; end;
  t := 0;
  if n <> 0 then read(t);
  b := b + t;
  f := l - b;
  n := n + 1;
  if f < 0 then writeln('0') else c_n_k(f + n - 1, n - 1);
end.
