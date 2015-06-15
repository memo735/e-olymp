var x1, y1, x2, y2, x3, y3, x4, y4:real; k:integer;

function check(a1, b1, a2, b2, a3, b3:real):boolean;
begin
  if (a1-a2)*(a3-a2)+(b1-b2)*(b3-b2)=0 then check:=true else check:=false;
end;

begin
  readln (x1, y1, x2, y2, x3, y3, x4, y4);
  k:=0;
  if check(x1, y1, x2, y2, x3, y3) then inc (k);
  if check(x2, y2, x3, y3, x4, y4) then inc (k);
  if check(x3, y3, x4, y4, x1, y1) then inc (k);
  if check(x4, y4, x1, y1, x2, y2) then inc (k);
  writeln (k);
end.
