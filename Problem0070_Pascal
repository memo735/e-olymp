var a, c:array[0..27,0..27] of int64; b:array[0..27,0..27] of boolean;
    count, r, n, i, j, max:longint; rez:int64;

procedure out;
begin
  writeln (rez);
end;

begin
  readln (r, n);
  fillchar (a, sizeof(a), 0);
  fillchar (c, sizeof(c), 0);
  fillchar (b, sizeof(b), false);
  max:=1;
  for i:=2 to r do max:=max+6*(i-1);
  if n>max then begin rez:=0; out; halt; end;
  count:=1;
  for i:=1 to r do
    for j:=1 to r+i-1 do
      begin
        a[i,j]:=count; b[i,j]:=true; inc (count);
      end;
  for i:=r+1 to r+r-1 do
    for j:=i-r+1 to r+r-1 do
      begin
        a[i,j]:=count; b[i,j]:=true; inc (count);
      end;
  for i:=1 to r do
    begin
      c[1,i]:=1; c[i,1]:=1;
    end;
  for i:=2 to 2*r-1 do
    for j:=2 to 2*r-1 do
      if b[i,j] then c[i,j]:=c[i-1,j]+c[i,j-1]+c[i-1,j-1];
  for i:=1 to 2*r-1 do
    for j:=1 to 2*r-1 do
      if a[i,j]=n then rez:=c[i,j];
  out;
end.
