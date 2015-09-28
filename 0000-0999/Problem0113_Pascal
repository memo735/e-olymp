var n, max, j, rez:longint; a:array[1..9] of longint;

procedure init;
var i, t:longint;
begin
  readln (n);
  for i:=1 to n do
    begin
      read (t); inc (a[t]);
    end;
end;

begin
  fillchar (a, sizeof(a),0);
  init; max:=a[1];
  for j:=2 to 9 do if a[j]>max then max:=a[j];
  rez:=n-max;
  writeln (rez);
end.
