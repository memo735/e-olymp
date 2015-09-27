var n,i: Integer; x,y: Array[1..1000] of Integer; sahe: Real;
begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  sahe:=0;
  for i:=1 to n-1 do sahe:=sahe+(x[i]*y[i+1]-x[i+1]*y[i]);
  sahe:=abs(sahe+(x[n]*y[1]-x[1]*y[n]))/2;
  writeln(sahe:0:3);
end.
