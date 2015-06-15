{Deikstra}
var d:array[1..366, 1..366] of longint; a, b, c, ma:array[1..366] of longint;
    check:boolean; n, m, k, t, i, j, start, i1, i2, i3, max, m1, v1:longint;

function min(x,y:longint):longint;
begin
  if x<y then min:=x else min:=y;
end;

PROCEDURE FindMinPath;
var Min,Mj,ii,jj:longint;
begin
  for ii:=1 to N do begin A[ii]:=0; B[ii]:=D[V1,ii]; C[ii]:=V1 end;
  A[V1]:=1;
  for ii:=1 to N-1 do
    begin
      Min:=200000; Mj:=0;
      for jj:=1 to N do
        if (A[jj]=0) and (B[jj]<Min) then begin Min:=B[jj]; Mj:=jj end;
      if Mj=0 then break;
      A[Mj]:=1;
      for jj:=1 to N do
        if (A[jj]=0) and (B[Mj]+D[Mj,jj]<B[jj]) then
          begin
            B[jj]:=B[Mj]+D[Mj,jj]; C[jj]:=Mj;
          end;
    end;
end;

begin
  readln (n, m, k);
  for i:=1 to m do read (ma[i]);
  readln;
  for i:=1 to n do
    for j:=1 to n do d[i,j]:=200000;
  for i:=1 to k do
    begin
      readln (i1, i2, i3);
      d[i1,i2]:=i3;
      d[i2,i1]:=i3;
    end;
  readln (start);
  v1:=start;
  findminpath;
  b[start]:=0;
  check:=false;
  for i:=1 to m do
    if b[ma[i]]=200000 then
      begin
        check:=true; break;
      end;
  if check then
    begin
      writeln ('It is not fault of sponsor...'); halt;
    end;
  max:=0;
  for i:=1 to m do if b[ma[i]]>max then max:=b[ma[i]];
  writeln ('The good sponsor!');
  writeln (max);
end.
