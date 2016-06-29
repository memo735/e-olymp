var xO, yO, xA, yA, xB, yB, xC, yC:real; rez:integer;
    OA, OB, OC, AB, AC, BC, s1, s2, s3, st :real;
procedure out;
begin
  writeln (rez); halt;
end;

function check (x, y, x1, y1, x2, y2:real):boolean;
var  p1,p2:real;
begin
  if (x=x1) and (x1=x2) and (((y>=y2) and (y<=y1)) or ((y>=y1) and (y<=y2))) then begin check:=true; exit; end;
  if (y=y1) and (y1=y2) and (((x>=x2) and (x<=x1)) or ((x>=x1) and (x<=x2))) then begin check:=true; exit; end;
  if (x=x1) and (x1=x2) and not((((y>=y2) and (y<=y1)) or ((y>=y1) and (y<=y2)))) then begin check:=false; exit; end;
  if (y=y1) and (y1=y2) and not((((x>=x2) and (x<=x1)) or ((x>=x1) and (x<=x2)))) then begin check:=false; exit; end;
  if (abs(x1-x2)>0.000000001) and (abs(y1-y2)>0.000000001) then
    begin
      p1:=(x-x2)/(x1-x2); p2:=(y-y2)/(y1-y2);
      if p1=p2 then
        if (p1>=0) and (p1<=1) then begin check:=true; exit; end;
    end;
  check:=false;
end;

function vid (xn, yn, xm, ym:real):real;
begin
  vid:=sqrt(sqr(xn-xm)+sqr(yn-ym));
end;

function S(a, b, c:real):real;
var p:real;
begin
  p:=(a+b+c)/2;
  s:=sqrt((p-a)*(p-b)*(p-c)*p);
end;

begin
  readln (xO, yO, xA, yA, xB, yB, xC, yC);
  if check (xO, yO, xA, yA, xB, yB) then begin rez:=1; out; halt; end;
  if check (xO, yO, xB, yB, xC, yC) then begin rez:=1; out; halt; end;
  if check (xO, yO, xC, yC, xA, yA) then begin rez:=1; out; halt; end;
  OA:=vid(xO, yO, xA, yA);
  OB:=vid(xO, yO, xB, yB);
  OC:=vid(xO, yO, xC, yC);
  AB:=vid(xB, yB, xA, yA);
  BC:=vid(xB, yB, xC, yC);
  AC:=vid(xA, yA, xC, yC);
  s1:=s(OA, OB, AB);
  s2:=s(OA, OC, AC);
  s3:=s(OB, OC, BC);
  st:=s(AB, AC, BC);
  if (s1+s2+s3)-st>0.00000001 then rez:=0 else rez:=1;
  out;
end.
