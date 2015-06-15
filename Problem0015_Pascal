var a:array[0..101, 0..101] of longint; m,n, i, j, k:integer; s:string;

function max(x, y:longint):longint;
begin
  if x>y then max:=x else max:=y;
end;

begin
  readln (m, n);
  if (m<>0) or (n<>0) then
    begin
      for i:=0 to m+1 do
        for j:=0 to n+1 do a[i,j]:=0;
      for i:=m downto 1 do
        begin
          for j:=1 to n do read (a[i,j]);
          readln;
       end;
    end;
  for i:=1 to m do a[i,1]:=a[i,1]+a[i-1,1];
  for j:=1 to n do a[1,j]:=a[1,j]+a[1,j-1];
  for i:=2 to m do
    for j:=2 to n do a[i,j]:=a[i,j]+max(a[i-1,j], a[i,j-1]);
  i:=m; j:=n; s:='';
  repeat
    if a[i,j-1]=a[i-1,j] then
      if i>1 then begin s:='F'+s; dec(i); end
    else
      if j>1 then begin s:='R'+s; dec(j); end;
    if a[i,j-1]<a[i-1,j] then
      begin
        if i>1 then
          begin
            s:='F'+s; dec(i);
          end;
      end
    else if j>1 then begin s:='R'+s; dec(j); end;
  until (i=1) and (j=1);
  for k:=1 to length(s) do write (s[k]);
  writeln;
end.
