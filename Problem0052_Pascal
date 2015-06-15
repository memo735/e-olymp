var a, h, z:longint; tz, tgz, rez:real;
begin
  readln (a, h, z);
  tz:=z*pi/180;
  tgz:=sin(tz)/cos(tz);
  if z=90 then rez:=a*h*sqrt(2) else
  if 2*h<a*tgz then rez:=(a*a/2-sqr(a-h*sqrt(2)/tgz)/2)/cos(tz)
  else rez:=a*a/2/cos(tz);
  writeln (rez:0:3);
end.
