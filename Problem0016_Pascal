var S, K, A, B, N, rez:longint;
begin
  readln (S, K, A, B);
  if s*a=b then writeln (s*k)
  else
    begin
      n:=1;
      while n<1001 do
        begin
          if (abs(s*a-b)) mod n =0 then
            begin
              rez:=((b-s*a) div n) +s*k;
              if (rez>=0) and (a>n*k) then
                begin
                  writeln (rez); halt;
                end;
            end;
          inc (n);
        end;
      if n=1001 then writeln (-1);
    end;
end.
