var s, d, m, y, d1, m1, y1:string; cifra: set of char; osnova, month, year, code:integer;

procedure solve (n:longint; osn:integer; var s2:string);
var i, k:integer; t:longint;
begin
  s2:='';
  while n>=1 do
    begin
      if n mod osn <10 then s2:=chr((n mod osn)+48)+s2
      else s2:=chr((n mod osn)+55)+s2;
      n:=n div osn;
    end;
end;

begin
  readln (s);
  d:=copy (s,1,pos('/',s)-1); val (d, osnova, code);
  delete (s,1,pos('/',s));
  m:=copy (s,1,pos('/',s)-1); val (m, month, code);
  delete (s,1,pos('/',s));
  y:=s; val (y, year, code);
  solve(osnova, osnova+1, d1);
  solve(month, osnova+1, m1);
  solve(year, osnova+1, y1);
  writeln (d1,'/',m1,'/',y1);
end.
