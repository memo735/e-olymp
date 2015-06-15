var t1, t2, t3:int64; r:real;
begin
  readln (t1, t2, t3);
  if ((t1=0)and(t2=0)and(t3=0)) or ((t1=0)and(t2=0)and(t3<>0)) or ((t1=0)and(t2<>0)and(t3=0)) or ((t1<>0)and(t2=0)and(t3=0))
  then begin writeln ('0.00'); halt; end;
  r:=t1*t2*t3/(t1*t2+t1*t3+t2*t3);
  writeln (r:0:2);
end.
