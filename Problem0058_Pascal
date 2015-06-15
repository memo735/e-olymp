var m, n, m1, n1, km, kn, EKOB, toqqusma, tor: Int64;

function EBOB(x, y: Int64): Int64;
begin
  while (x<>0) and (y<>0) do if x>=y then x:=x mod y else y:=y mod x;
  EBOB:=x+y;
end;

begin
  readln (m1, n1); toqqusma:=0;
  m:= m1 div EBOB(m1, n1);
  n:= n1 div EBOB(m1, n1);
  
  EKOB:=(m*n) div EBOB(m, n);
  km:=EKOB div m; kn:=EKOB div n;
  
  if (km mod 2 = 1) and (kn mod 2 = 0) then tor:=2;
  if (km mod 2 = 1) and (kn mod 2 = 1) then tor:=3;
  if (km mod 2 = 0) and (kn mod 2 = 1) then tor:=4;
  toqqusma:=(km - 1) + (kn - 1);
  writeln (toqqusma, ' ',tor);
end.
