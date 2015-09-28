var a, b, c, mn:longint; lent, j:integer; flag:boolean; temp:string;
begin
  readln (a, c);
  b:=a; flag:=true;
  while flag do
    begin
      if a mod c=0 then flag:=false
      else
        begin
          inc(b); str (b, temp);
          lent:=length(temp); mn:=1;
          for j:=1 to lent do mn:=mn*10;
          a:=(a mod c)*mn+b;
        end;
    end;
  writeln (b);
end.
