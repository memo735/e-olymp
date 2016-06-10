var i,max,n:integer; d,c:array[1..15] of integer;

procedure recurs(k,s:integer);
var f,q,j:integer;
begin
  f:=0;
  for j:=1 to n do
    if d[j]>=k then
      begin
        q:=(d[j]-k+1)*c[j];
        f:=d[j]; d[j]:=0;
        recurs(k+1,s+q);
        d[j]:=f; f:=1;
      end;
  if f=0 then
    if max<s then max:=s;
end;

begin
  read(n);
  for i:=1 to n do read(d[i],c[i]);
  recurs(1,0);
  writeln(max);
end.
