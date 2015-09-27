type TPoint=record
            x,y:real;
            end;
var fi, fo:text; p0t, p1t, p2t, p3t:TPoint;
    x, y, s, s1, rez, a, b, c, h, temp:real; k:integer;

function min(xx, yy:real):real;
begin
  if xx<yy then min:=xx else min:=yy;
end;

function max(xx, yy:real):real;
begin
  if xx>yy then max:=xx else max:=yy;
end;

function peret(p0, p1, p2, p3:TPoint):boolean;
begin
  peret:=false;
  if((max(p0.x,p1.x)>=min(p2.x,p3.x)) and (max(p2.x,p3.x)>=min(p0.x,p1.x)) and (max(p0.y,p1.y)>=min(p2.y,p3.y)) and (max(p2.y,p3.y)>=min(p0.y,p1.y))) then
    if (((p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y))*((p3.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p3.y-p0.y))<=0) then
      if (((p0.x-p2.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p0.y-p2.y))*((p1.x-p2.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p1.y-p2.y))<=0) then peret:=true;
end;

procedure point_peret(p0, p1, p2, p3:TPoint; var xt, yt:real; var kk:integer);
var a1, b1, c1, a2, b2, c2, d, dx, dy:real;
begin
  kk:=1;
  a1:=p1.y-p0.y; b1:=p0.x-p1.x; c1:=p0.x*p1.y-p0.y*p1.x;
  a2:=p3.y-p2.y; b2:=p2.x-p3.x; c2:=p2.x*p3.y-p2.y*p3.x;
  d:=a1*b2-a2*b1; dx:=c1*b2-c2*b1; dy:=a1*c2-a2*c1;
  xt:=dx/d; yt:=dy/d;
end;

function vid(xa, ya, xb, yb:real):real;
begin
  vid:=sqrt(sqr(xa-xb)+sqr(ya-yb));
end;

function variant (x0, y0, x1, y1, x2, y2, x3, y3:real):integer;
begin
  if (x0<=x1) and (y0<=y1) and (x1<=x2) and (y1<=y2) and (x2<=x3) and (y2<=y3) or
     (x0>=x1) and (y0<=y1) and (x1>=x2) and (y1<=y2) and (x2>=x3) and (y2<=y3) or
     (x0>=x1) and (y0>=y1) and (x1>=x2) and (y1>=y2) and (x2>=x3) and (y2>=y3) or
     (x0>=x1) and (y0<=y1) and (x1>=x2) and (y1<=y2) and (x2>=x3) and (y2<=y3) then variant:=1;
  if (x0<=x1) and (y0<=y1) and (x1<=x3) and (y1<=y3) and (x3<=x2) and (y3<=y2) or
     (x0>=x1) and (y0<=y1) and (x1>=x3) and (y1<=y3) and (x3>=x2) and (y3<=y2) or
     (x0>=x1) and (y0>=y1) and (x1>=x3) and (y1>=y3) and (x3>=x2) and (y3>=y2) or
     (x0>=x1) and (y0<=y1) and (x1>=x3) and (y1<=y3) and (x3>=x2) and (y3<=y2) then variant:=2;
  if (x1<=x0) and (y1<=y0) and (x0<=x2) and (y0<=y2) and (x2<=x3) and (y2<=y3) or
     (x1>=x0) and (y1<=y0) and (x0>=x2) and (y0<=y2) and (x2>=x3) and (y2<=y3) or
     (x1>=x0) and (y1>=y0) and (x0>=x2) and (y0>=y2) and (x2>=x3) and (y2>=y3) or
     (x1>=x0) and (y1<=y0) and (x0>=x2) and (y0<=y2) and (x2>=x3) and (y2<=y3) then variant:=3;
  if (x1<=x0) and (y1<=y0) and (x0<=x3) and (y0<=y3) and (x3<=x2) and (y3<=y2) or
     (x1>=x0) and (y1<=y0) and (x0>=x3) and (y0<=y3) and (x3>=x2) and (y3<=y2) or
     (x1>=x0) and (y1>=y0) and (x0>=x3) and (y0>=y3) and (x3>=x2) and (y3>=y2) or
     (x1>=x0) and (y1<=y0) and (x0>=x3) and (y0<=y3) and (x3>=x2) and (y3<=y2) then variant:=4;
  if (x0<=x3) and (y0<=y3) and (x3<=x1) and (y3<=y1) and (x1<=x2) and (y1<=y2) or
     (x0>=x3) and (y0<=y3) and (x3>=x1) and (y3<=y1) and (x1>=x2) and (y1<=y2) or
     (x0>=x3) and (y0>=y3) and (x3>=x1) and (y3>=y1) and (x1>=x2) and (y1>=y2) or
     (x0>=x3) and (y0<=y3) and (x3>=x1) and (y3<=y1) and (x1>=x2) and (y1<=y2) then variant:=5;
  if (x0<=x3) and (y0<=y3) and (x3<=x2) and (y3<=y2) and (x2<=x1) and (y2<=y1) or
     (x0>=x3) and (y0<=y3) and (x3>=x2) and (y3<=y2) and (x2>=x1) and (y2<=y1) or
     (x0>=x3) and (y0>=y3) and (x3>=x2) and (y3>=y2) and (x2>=x1) and (y2>=y1) or
     (x0>=x3) and (y0<=y3) and (x3>=x2) and (y3<=y2) and (x2>=x1) and (y2<=y1) then variant:=6;
  if (x0<=x2) and (y0<=y2) and (x2<=x1) and (y2<=y1) and (x1<=x3) and (y1<=y3) or
     (x0>=x2) and (y0<=y2) and (x2>=x1) and (y2<=y1) and (x1>=x3) and (y1<=y3) or
     (x0>=x2) and (y0>=y2) and (x2>=x1) and (y2>=y1) and (x1>=x3) and (y1>=y3) or
     (x0>=x2) and (y0<=y2) and (x2>=x1) and (y2<=y1) and (x1>=x3) and (y1<=y3) then variant:=7;
  if (x0<=x2) and (y0<=y2) and (x2<=x3) and (y2<=y3) and (x3<=x1) and (y3<=y1) or
     (x0>=x2) and (y0<=y2) and (x2>=x3) and (y2<=y3) and (x3>=x1) and (y3<=y1) or
     (x0>=x2) and (y0>=y2) and (x2>=x3) and (y2>=y3) and (x3>=x1) and (y3>=y1) or
     (x0>=x2) and (y0<=y2) and (x2>=x3) and (y2<=y3) and (x3>=x1) and (y3<=y1) then variant:=8;
  if (x1<=x2) and (y1<=y2) and (x2<=x0) and (y2<=y0) and (x0<=x3) and (y0<=y3) or
     (x1>=x2) and (y1<=y2) and (x2>=x0) and (y2<=y0) and (x0>=x3) and (y0<=y3) or
     (x1>=x2) and (y1>=y2) and (x2>=x0) and (y2>=y0) and (x0>=x3) and (y0>=y3) or
     (x1>=x2) and (y1<=y2) and (x2>=x0) and (y2<=y0) and (x0>=x3) and (y0<=y3) then variant:=9;
  if (x1<=x3) and (y1<=y3) and (x3<=x0) and (y3<=y0) and (x0<=x2) and (y0<=y2) or
     (x1>=x3) and (y1<=y3) and (x3>=x0) and (y3<=y0) and (x0>=x2) and (y0<=y2) or
     (x1>=x3) and (y1>=y3) and (x3>=x0) and (y3>=y0) and (x0>=x2) and (y0>=y2) or
     (x1>=x3) and (y1<=y3) and (x3>=x0) and (y3<=y0) and (x0>=x2) and (y0<=y2) then variant:=10;
  if (x2<=x0) and (y2<=y0) and (x0<=x1) and (y0<=y1) and (x1<=x3) and (y1<=y3) or
     (x2>=x0) and (y2<=y0) and (x0>=x1) and (y0<=y1) and (x1>=x3) and (y1<=y3) or
     (x2>=x0) and (y2>=y0) and (x0>=x1) and (y0>=y1) and (x1>=x3) and (y1>=y3) or
     (x2>=x0) and (y2<=y0) and (x0>=x1) and (y0<=y1) and (x1>=x3) and (y1<=y3) then variant:=11;
  if (x2<=x1) and (y2<=y1) and (x1<=x0) and (y1<=y0) and (x0<=x3) and (y0<=y3) or
     (x2>=x1) and (y2<=y1) and (x1>=x0) and (y1<=y0) and (x0>=x3) and (y0<=y3) or
     (x2>=x1) and (y2>=y1) and (x1>=x0) and (y1>=y0) and (x0>=x3) and (y0>=y3) or
     (x2>=x1) and (y2<=y1) and (x1>=x0) and (y1<=y0) and (x0>=x3) and (y0<=y3) then variant:=12;
end;

procedure line(p0, p1, p2, p3:TPoint; var rezt:real);
var p0p1, p0p2, p0p3, p1p2, p1p3, p2p3:real; tem:integer;
begin
  p0p1:=vid(p0.x, p0.y, p1.x, p1.y);
  p0p2:=vid(p0.x, p0.y, p2.x, p2.y);
  p0p3:=vid(p0.x, p0.y, p3.x, p3.y);
  p1p2:=vid(p1.x, p1.y, p2.x, p2.y);
  p1p3:=vid(p1.x, p1.y, p3.x, p3.y);
  p2p3:=vid(p2.x, p2.y, p3.x, p3.y);
  rezt:=0;
  tem:=variant(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
  if tem=5 then if (sqrt(p0p1*p0p1-p0p3*p0p3)<=h) then begin rezt:=p0p1*arctan(sqrt(p0p1*p0p1-p0p3*p0p3)/p0p3); exit; end;
  if tem=5 then if (sqrt(p0p1*p0p1-p0p3*p0p3)>h) then begin rezt:=p0p1*arctan(h/sqrt(p0p1*p0p1-h*h)); exit; end;
  if tem=6 then if (sqrt(p0p1*p0p1-p0p3*p0p3)<=h) then begin rezt:=p0p1*(arctan(sqrt(p0p1*p0p1-p0p3*p0p3)/p0p3)-arctan(sqrt(p0p1*p0p1-p0p2*p0p2)/p0p2)); exit; end;
  if tem=6 then if (sqrt(p0p1*p0p1-p0p3*p0p3)>h) and (sqrt(p0p1*p0p1-p0p2*p0p2)<h) and (p0p2<>0) then begin rezt:=p0p1*(arctan(h/sqrt(p0p1*p0p1-h*h))-arctan(sqrt(p0p1*p0p1-p0p2*p0p2)/p0p2)); exit; end;
  if tem=7 then if (sqrt(p0p1*p0p1-p0p2*p0p2)<=h) then begin rezt:=p0p1*arctan(sqrt(p0p1*p0p1-p0p2*p0p2)/p0p2); exit; end;
  if tem=7 then if (sqrt(p0p1*p0p1-p0p2*p0p2)>h) then begin rezt:=p0p1*arctan(h/sqrt(p0p1*p0p1-h*h)); exit; end;
  if tem=8 then if (sqrt(p0p1*p0p1-p0p2*p0p2)<=h) then begin rezt:=p0p1*(arctan(sqrt(p0p1*p0p1-p0p2*p0p2)/p0p2)-arctan(sqrt(p0p1*p0p1-p0p3*p0p3)/p0p3)); exit; end;
  if tem=8 then if (sqrt(p0p1*p0p1-p0p2*p0p2)>h) and (sqrt(p0p1*p0p1-p0p3*p0p3)<h){ and (p0p3<>0)} then begin rezt:=p0p1*(arctan(h/sqrt(p0p1*p0p1-h*h))-arctan(sqrt(p0p1*p0p1-p0p3*p0p3)/p0p3)); exit; end;
  if tem=9 then if (p0p1<=h) then begin rezt:=p0p1*(pi/2-arctan(sqrt(p0p1*p0p1-p0p2*p0p2)/p0p2)); exit; end;
  if tem=9 then if (p0p1>h) and (sqrt(p0p1*p0p1-p0p2*p0p2)<h) then begin rezt:=p0p1*(arctan(h/sqrt(p0p1*p0p1-h*h))-arctan(sqrt(p0p1*p0p1-p0p2*p0p2)/p0p2)); exit; end;
  if tem=10 then if (p0p1<=h) then begin rezt:=p0p1*(pi/2-arctan(sqrt(p0p1*p0p1-p0p3*p0p3)/p0p3)); exit; end;
  if tem=10 then if (p0p1>h) and (sqrt(p0p1*p0p1-p0p3*p0p3)<h) then begin rezt:=p0p1*(arctan(h/sqrt(p0p1*p0p1-h*h))-arctan(sqrt(p0p1*p0p1-p0p3*p0p3)/p0p3)); exit; end;
  if tem=11 then if p0p1<=h then begin rezt:=p0p1*pi/2; exit; end;
  if tem=11 then if p0p1>h then begin rezt:=p0p1*arctan(h/sqrt(p0p1*p0p1-h*h)); exit; end;
  if tem=12 then if p0p1<=h then begin rezt:=p0p1*pi/2; exit; end;
  if tem=12 then if p0p1>h then begin rezt:=p0p1*arctan(h/sqrt(p0p1*p0p1-h*h)); exit; end;
end;

begin
  readln (p0t.x, p0t.y, p1t.x, p1t.y, p2t.x, p2t.y, p3t.x, p3t.y, h);
  a:=p1t.y-p0t.y;  b:=p0t.x-p1t.x;  c:=p0t.x*p1t.y-p0t.y*p1t.x;
  if (a*p2t.x+b*p2t.y=c) and (a*p3t.x+b*p3t.y=c) then line (p0t, p1t, p2t, p3t, rez)
  else
    if peret(p0t, p1t, p2t, p3t) then
      begin
        point_peret(p0t, p1t, p2t, p3t, x, y, k);
        if k>0 then
          begin
            s:=vid(p0t.x, p0t.y, x, y);
            s1:=vid(p0t.x, p0t.y, p1t.x, p1t.y);
            if s1>s then rez:=sqrt(sqr(s1)-sqr(s));
            if rez>h then rez:=h;
            if (x=p2t.x) and (y=p2t.y) or (x=p3t.x) and (y=p3t.y) then rez:=0;
            if s=0 then rez:=0;
          end
        else rez:=0;
      end;
  writeln (rez:0:3);
end.
