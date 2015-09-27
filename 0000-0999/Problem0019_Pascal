var s:string; n, k, i:integer; c:char;
begin
  s:=''; read (c);
  while c in ['0'..'9'] do
    begin
      s:=s+c; read(c);
    end;
  k:=0; n:=length(s);
  if n mod 2 = 1 then
    begin
      for i:=1 to (n div 2)+1 do
        if s[i]=s[n-i+1] then inc (k) end
        else
          begin
            for i:=1 to n div 2 do
              if s[i]=s[n-i+1] then inc (k);
          end;
  writeln (k);
end.
