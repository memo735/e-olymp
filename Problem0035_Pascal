var i, a, n, s: int64; j, t:longint;
procedure out;
begin
  writeln (s);
  halt;
end;

begin
  readln (n);
  if n<1 then begin writeln (0); halt; end;
  i:=1; a:=0;
  while a<n do
    begin
      a:=6*i*i;
      inc(i);
    end;
  i:=i-1;
  if i=1 then
    case n of
      1: begin s:=3; out; end;
      2: begin s:=5; out; end;
      3: begin s:=7; out; end;
      4: begin s:=9; out; end;
      5: begin s:=11; out; end;
      6: begin s:=12; out; end;
    end;
  if i=2 then
    case n of
      7: begin s:=14; out; end;
      8: begin s:=16; out; end;
      9: begin s:=18; out; end;
      10: begin s:=19; out; end;
      11: begin s:=21; out; end;
      12: begin s:=23; out; end;
      13: begin s:=24; out; end;
      14: begin s:=26; out; end;
      15: begin s:=28; out; end;
      16: begin s:=29; out; end;
      17: begin s:=31; out; end;
      18: begin s:=33; out; end;
      19: begin s:=34; out; end;
      20: begin s:=36; out; end;
      21: begin s:=38; out; end;
      22: begin s:=39; out; end;
      23: begin s:=41; out; end;
      24: begin s:=42; out; end;
    end;
  s:=0; a:=12;
  for j:=1 to i-1 do
    begin
      s:=s+a;
      a:=a+18;
    end;
  n:=n-6*(i-1)*(i-1);
  if n>1 then begin s:=s+2; n:=n-1; end;
  for j:=1 to i-2 do
    begin
      if n>0 then begin s:=s+2; n:=n-1; end;
      if n=0 then break;
      if n>0 then begin s:=s+1; n:=n-1; end;
      if n=0 then break;
    end;
  for t:=1 to 5 do
    begin
      if n>0 then begin s:=s+2; n:=n-1; end;
      if n=0 then break;
      for j:=1 to i-1 do
        begin
          if n>0 then begin s:=s+2; n:=n-1; end;
          if n=0 then break;
          if n>0 then begin s:=s+1; n:=n-1; end;
          if n=0 then break;
        end;
      if n=0 then break;
    end;
  if n>0 then begin s:=s+2; n:=n-1; end;
  if n=0 then out;
  if n>0 then begin s:=s+1; n:=n-1; end;
  if n=0 then out;
end.
