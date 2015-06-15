var a, b, c, x1, y1, x2, y2, z2:longint; r, r1, r2, r3, r4, min:real;

function s(xa, ya, xb, yb:longint):real;
begin
  s:=sqrt(sqr(xa-xb)+sqr(ya-yb));
end;

procedure out;
begin
  writeln (r:0:2);
  halt;
end;

begin
  readln (a, b, c);
  readln (x1, y1, x2, y2, z2);
  if z2=0 then begin r:=s(x1, y1, x2, y2); out; end;
  if x2=0 then
    begin
      if y2=b then if x1+y1<b then begin r:=s(x1, y1, -z2, y2); out; end;
      r:=s(x1, y1, -z2, y2); out;
    end;
  if x2=a then begin r:=s(x1, y1, a+z2, y2); out; end;
  if x2=b then begin r:=s(x1, y1, b+z2, y2); out; end;
  if y2=0 then begin r:=s(x1, y1, x2, -z2); out; end;
  if (y2=b) and (x2<>0) then begin r:=s(x1, y1, x2, b+z2); out; end;
  if y2=a then begin r:=s(x1, y1, x2, a+z2); out; end;
end.
