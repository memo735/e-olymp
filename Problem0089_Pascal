var s:int64; n, k, i, j, t, a:longint; c:char;
begin
  readln (n);
  for i:=1 to n do
    begin
      readln (k);
      s:=k*6;
      for j:=1 to k do
        begin
          read (c);
          while c<>':' do read (c);
          t:=0;
          repeat
            read (a); inc (t);
          until a=0;
          readln;
          s:=s-t+1;
        end;
      writeln (s);
    end;
end.
