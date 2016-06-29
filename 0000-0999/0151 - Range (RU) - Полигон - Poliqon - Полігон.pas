type p=record
     x, y:real;
     end;
var a:array [1..22] of p;
    b:array [1..20] of integer;
    s, n, i, rez, number:integer;

function cut(p0, p1, p2:p):integer;
begin
  if (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)>0 then cut:=1;
  if (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)<0 then cut:=-1;
  if (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)=0 then cut:=0;
end;

begin
  readln (n);
  for i:=1 to n do readln (a[i].x, a[i].y);
  a[n+1].x:=a[1].x; a[n+1].y:=a[1].y;
  a[n+2].x:=a[2].x; a[n+2].y:=a[2].y;
  s:=0;
  for i:=1 to n do
    begin
      b[i]:=cut(a[i], a[i+1], a[i+2]);
      s:=s+b[i];
    end;
  if s>0 then rez:=-1 else rez:=1;
  for i:=1 to n do if b[i]=rez then number:=i;
  if number>=n then number:=number mod n;
  writeln (number+1);
end.
