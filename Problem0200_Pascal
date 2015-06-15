type tpoint=record
     x, y:integer;
     end;
var a, b, c, d:tpoint; rez:string;

function vid(x1, y1, x2, y2:integer):real;
begin
  vid:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;

function kvadrat (a1, b1, c1, d1:tpoint):boolean;
begin
  if (vid (a1.x, a1.y, c1.x, c1.y)<0.00001) or
     (vid (a1.x, a1.y, b1.x, b1.y)<0.00001) or
     (vid (a1.x, a1.y, d1.x, d1.y)<0.00001) or
     (vid (b1.x, b1.y, c1.x, c1.y)<0.00001) or
     (vid (b1.x, b1.y, d1.x, d1.y)<0.00001) or
     (vid (c1.x, c1.y, d1.x, d1.y)<0.00001) then begin kvadrat:=false; exit; end;
  if abs(vid (a1.x, a1.y, c1.x, c1.y)-vid (b1.x, b1.y, d1.x, d1.y))>0.000001 then begin kvadrat:=false; exit; end;
  if abs((a1.x-c1.x)*(b1.x-d1.x)+(a1.y-c1.y)*(b1.y-d1.y))>0.000001 then begin kvadrat:=false; exit; end;
  if (abs((a1.x+c1.x)/2-(b1.x+d1.x)/2)>0.000001) or (abs((a1.y+c1.y)/2-(b1.y+d1.y)/2)>0.000001) then begin kvadrat:=false; exit; end;
  kvadrat:=true;
end;

begin
  readln (a.x, a.y); readln (b.x, b.y);
  readln (c.x, c.y); readln (d.x, d.y);
  rez:='NO';
  if kvadrat(a, b, c, d) then rez:='YES';
  if kvadrat(a, b, d, c) then rez:='YES';
  if kvadrat(a, c, b, d) then rez:='YES';
  if kvadrat(a, c, d, b) then rez:='YES';
  if kvadrat(a, d, b, c) then rez:='YES';
  if kvadrat(a, d, c, b) then rez:='YES';
  if kvadrat(b, a, c, d) then rez:='YES';
  if kvadrat(b, a, d, c) then rez:='YES';
  if kvadrat(b, c, a, d) then rez:='YES';
  if kvadrat(b, c, d, a) then rez:='YES';
  if kvadrat(b, d, a, c) then rez:='YES';
  if kvadrat(b, d, c, a) then rez:='YES';
  if kvadrat(c, a, b, d) then rez:='YES';
  if kvadrat(c, a, d, b) then rez:='YES';
  if kvadrat(c, b, a, d) then rez:='YES';
  if kvadrat(c, b, d, a) then rez:='YES';
  if kvadrat(c, d, a, b) then rez:='YES';
  if kvadrat(c, d, b, a) then rez:='YES';
  if kvadrat(d, a, b, c) then rez:='YES';
  if kvadrat(d, a, c, b) then rez:='YES';
  if kvadrat(d, b, a, c) then rez:='YES';
  if kvadrat(d, b, c, a) then rez:='YES';
  if kvadrat(d, c, a, b) then rez:='YES';
  if kvadrat(d, c, b, a) then rez:='YES';
  writeln (rez);
end.
