var m, n, xp, yp, xk, yk, st, fin, temp, rez :longint;
begin
  readln (n, m);
  readln (st, fin);
  if n=1 then begin rez:=abs(st-fin); writeln (rez); halt; end;
  if m=1 then begin rez:=abs(st-fin); writeln (rez); halt; end;
  if st>fin then begin temp:=st; st:=fin; fin:=temp; end;
  xp:=((st-1) div (2*n))+1;
  yp:=(((st-1) mod (2*n)) div 2)+1;
  xk:=((fin-1) div (2*n))+1;
  yk:=(((fin-1) mod (2*n)) div 2)+1;
  if (xp=xk) then begin rez:=abs(st-fin); writeln (rez); halt; end;
  if (yp=yk) and (st mod 2 = fin mod 2) then begin rez:=abs(xk-xp)*2; writeln (rez); halt; end;
  if (yp=yk) and (st mod 2 =0) and (fin mod 2=1) then begin rez:=abs(xk-xp)*2-1; writeln (rez); halt; end;
  if (yp=yk) and (st mod 2 =1) and (fin mod 2=0) then begin rez:=abs(xk-xp)*2+1; writeln (rez); halt; end;
  if (xp<xk) and (yp<yk) and (st mod 2 = fin mod 2) then begin rez:=abs(xk-xp)*2+abs(yk-yp)*2; writeln (rez); halt; end;
  if (xp<xk) and (yp<yk) and (st mod 2 =0) and (fin mod 2=1) then begin rez:=abs(xk-xp)*2+abs(yk-yp)*2-1; writeln (rez); halt; end;
  if (xp<xk) and (yp<yk) and (st mod 2 =1) and (fin mod 2=0) then begin rez:=abs(xk-xp)*2+abs(yk-yp)*2+1; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp=xk+yk) and (st mod 2 = fin mod 2) then begin rez:=abs(yk-yp)*2; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp>xk+yk) and (st mod 2 = fin mod 2) then begin rez:=abs(xk-xp)*2; yp:=yp-abs(xp-xk); rez:=rez+abs(yp-yk)*2; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp>xk+yk) and (st mod 2=0) and (fin mod 2=1) then begin rez:=abs(xk-xp)*2; yp:=yp-abs(xp-xk); rez:=rez+abs(yp-yk)*2+1; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp>xk+yk) and (st mod 2=1) and (fin mod 2=0) then begin rez:=abs(xk-xp)*2; yp:=yp-abs(xp-xk); rez:=rez+abs(yp-yk)*2-1; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp<xk+yk) and (st mod 2 = fin mod 2) then begin rez:=abs(yk-yp)*2; xp:=xp+abs(yp-yk); rez:=rez+abs(xp-xk)*2; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp<xk+yk) and (st mod 2=0) and (fin mod 2=1) then begin rez:=abs(yk-yp)*2; xp:=xp+abs(yp-yk); rez:=rez+abs(xp-xk)*2-1; writeln (rez); halt; end;
  if (xp<xk) and (yp>yk) and (xp+yp<xk+yk) and (st mod 2=1) and (fin mod 2=0) then begin rez:=abs(yk-yp)*2; xp:=xp+abs(yp-yk); rez:=rez+abs(xp-xk)*2+1; writeln (rez); halt; end;
end.
