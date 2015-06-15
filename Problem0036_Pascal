var  n, m, m1, n1:longint;
begin
  readln (n, m);
  if (m=0) and (n=0) then begin writeln (0); halt; end;
  if (m=0) and (n mod 2=1) then begin writeln (-1); halt; end;
  if (m=0) and (n mod 2=0) then begin writeln (n div 2); halt; end;
  if (n mod 2=0) and (m mod 4=1) then begin m1:=(m div 4);    n1:=n+m1*2; writeln ((n1 div 2)+m1*2+6);  halt; end;
  if (n mod 2=0) and (m mod 4=2) then begin m1:=(m div 4);    n1:=n+m1*2; writeln ((n1 div 2)+m1*2+5);  halt; end;
  if (n mod 2=0) and (m mod 4=3) then begin m1:=(m div 4);    n1:=n+m1*2; writeln ((n1 div 2)+m1*2+4);  halt; end;
  if (n mod 2=0) and (m mod 4=0) then begin m1:=(m div 4)-1;  n1:=n+2*m1; writeln ((n1 div 2)+m1*2+3);  halt; end;  
  if (n mod 2=1) and (m mod 4=0) then begin m1:=(m div 4)-1;  n1:=n+m1*2; writeln ((n1 div 2)+m1*2+7);  halt; end;
  if (n mod 2=1) and (m mod 4=1) then begin m1:=(m div 4);    n1:=n+m1*2; writeln ((n1 div 2)+m1*2+3);  halt; end;
  if (n mod 2=1) and (m mod 4=2) then begin m1:=(m div 2);    n1:=n+m1;   writeln ((n1 div 2)+m1);      halt; end;
  if (n mod 2=1) and (m mod 4=3) then begin m1:=(m div 4);    n1:=n+m1*2; writeln ((n1 div 2)+m1*2+8);  halt; end;
end.
