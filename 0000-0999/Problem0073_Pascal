Const MaxDig=1010; Osn=10;
Type Tlong=Array [0..MaxDig] of longint;
var a:array[0..10000] of tlong; b, c:array [0..9] of longint;
    a1, a2, fib:tlong; i, sc, rez:longint;

function check:boolean;
var j, sumb:integer;
begin
  fillchar (b,sizeof(b),0);
  for j:=1 to fib[0] do inc (b[fib[j]]);
  check:=true;
  for j:=0 to 9 do
    if b[j]>c[j] then begin check:=false; exit; end;
end;

Procedure SumLongTwo (t, p:Tlong; Var s:Tlong);
Var i, k:Integer;
Begin
  FillChar (s, Sizeof(s), 0);
  If t[0]>p[0] Then k:=t[0] Else k:=p[0];
  For i:=1 to k Do
    Begin
	    s[i+1]:=(t[i]+p[i]+s[i]) div Osn;
	    s[i]:=(t[i]+p[i]+s[i]) Mod Osn;
    End;
  If s[k+1]=0 Then s[0]:=k Else s[0]:=k+1;
End;

begin
  sc:=0;
  for i:=0 to 9 do
    begin
      read (c[i]); sc:=sc+c[i];
    end;
  a[1][0]:=1; a[1][1]:=1;
  a[2][0]:=1; a[2][1]:=1;
  rez:=2; i:=2;
  while (a[i][0]<=sc) do
    begin
      inc (i);
      sumlongtwo (a[i-2], a[i-1], a[i]);
      inc(rez);
    end;
  fib:=a[i-1];
  while not(check) do
    begin
      i:=i-1; fib:=a[i]; dec(rez);
    end;
  if rez>0 then writeln (rez) else writeln (-1);
end.
