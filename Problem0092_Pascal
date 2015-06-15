type list = array[1..1000] of longint;
var mas: list; temp, ii, k, jj, t, p, s: longint;

procedure sort(l,r: longint);
var i1,j1: longint; x, y:longint;
begin
  i1:=l; j1:=r; x:=mas[(l+r) DIV 2];
  repeat
    while mas[i1]<x do i1:=i1+1;
    while x<mas[j1] do j1:=j1-1;
    if i1<=j1 then
      begin
        y:=mas[i1]; mas[i1]:=mas[j1]; mas[j1]:=y;
        i1:=i1+1; j1:=j1-1;
      end;
  until i1>j1;
  if l<j1 then sort(l,j1);
  if i1<r then sort(i1,r);
end;

begin
  readln (k);
  for ii:=1 to k do
    begin
      read (t); read (p);
      for jj:=1 to p do read (mas[jj]); readln;
      {if p=2 then begin if mas[2]<mas[1] then begin temp:=mas[1];mas[1]:=mas[2];mas[2]:=temp;end; end
       else} sort(1,p);
      s:=0;
      if t>p then t:=p;
      for jj:=p downto p-t+1 do s:=s+mas[jj];
      writeln (s);
      fillchar (mas,sizeof(mas),0);
    end;
end.
