const eps=1e-6;
var i, x1, y1, x2, y2, rez:longint;

function vid(ax, ay, bx, by:longint):real;
var t:real;
begin
  vid:=sqrt(sqr(ax-bx)+sqr(ay-by));
end;

function S(a, b, c:real):real;
var p:real;
begin
  p:=(a+b+c)/2;
  s:=sqrt(p*(p-a)*(p-b)*(p-c));
end;

function cosf(a1, a2, b1, b2:longint):real;
begin
  cosf:=(a1*b1+a2*b2);
end;

function peret(r0, xa, ya, xb, yb:longint):integer;
var h, sp, va, vb, q, r:real;
begin
  r:=r0*1.0;
  if (vid (0,0,xa,ya)<r) and (vid (0,0,xb,yb)<r) then begin peret:=0; exit; end;
  if (vid (0,0,xa,ya)<r) and (vid (0,0,xb,yb)>r) then begin peret:=1; exit; end;
  if (vid (0,0,xb,yb)<r) and (vid (0,0,xa,ya)>r) then begin peret:=1; exit; end;
  if (abs(vid (0,0,xa,ya)-r)<eps) and (vid (0,0,xb,yb)<r) then begin peret:=1; exit; end;
  if (abs(vid (0,0,xb,yb)-r)<eps) and (vid (0,0,xa,ya)<r) then begin peret:=1; exit; end;
  if (abs(vid (0,0,xb,yb)-r)<eps) and (abs(vid (0,0,xa,ya)-r)<eps) then begin peret:=2; exit; end;
  if (abs(vid (0,0,xa,ya)-r)<eps) and (vid (0,0,xb,yb)>r) and (cosf(0-xa, 0-ya, xb-xa, yb-ya)<=0) then begin peret:=1; exit; end;
  if (abs(vid (0,0,xa,ya)-r)<eps) and (vid (0,0,xb,yb)>r) and (cosf(0-xa, 0-ya, xb-xa, yb-ya)>0) then begin peret:=2; exit; end;
  if (abs(vid (0,0,xb,yb)-r)<eps) and (vid (0,0,xa,ya)>r) and (cosf(0-xb, 0-yb, xa-xb, ya-yb)<=0) then begin peret:=1; exit; end;
  if (abs(vid (0,0,xb,yb)-r)<eps) and (vid (0,0,xa,ya)>r) and (cosf(0-xb, 0-yb, xa-xb, ya-yb)>0) then begin peret:=2; exit; end;
  sp:=s(vid(0,0,xa,ya),vid(0,0,xb,yb),vid(xa,ya,xb,yb));
  h:=2*sp/vid(xa,ya,xb,yb);
  if (vid (0,0,xa,ya)>r) and (vid (0,0,xb,yb)>r) and (cosf(0-xa, 0-ya, xb-xa, yb-ya)*cosf(0-xb, 0-yb, xa-xb, ya-yb)>0) then
    begin
      if r-h>eps then begin peret:=2; exit; end;
      if h-r>eps then begin peret:=0; exit; end;
      if abs(h-r)<eps then begin peret:=1; exit; end;
    end;
  if (vid (0,0,xa,ya)>r) and (vid (0,0,xb,yb)>r) and (cosf(0-xa, 0-ya, xb-xa, yb-ya)*cosf(0-xb, 0-yb, xa-xb, ya-yb)<=0) then begin peret:=0; exit; end;
end;

begin
  readln (x1, y1, x2, y2);
  rez:=0;
  for i:=1 to 1500 do rez:=rez+peret (i, x1, y1, x2, y2);
  writeln (rez);
end.
