CONST Dim = 100;
type point=record
     x,y:integer;
     end;
VAR A:Array[1..Dim,1..Dim] of real; Col:Array[1..Dim] of integer;
    Res:Array[1..2,1..Dim] of integer;
    N, ip, ik, ni:integer; i,j:integer;
    minr, r:real; LenOstov:real;
    s:array[1..100] of point;

function vid(x1, y1, x2, y2:integer):real;
begin
  vid:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;

PROCEDURE ReadData;
begin
  readln(N);
  for i:=1 to n do
    for j:=1 to n do a[i,j]:=10000;
  for i:=1 to n do readln (s[i].x, s[i].y);
  for i:=1 to n-1 do
    begin
      for j:=i+1 to n do
        begin
          r:=vid (s[i].x,s[i].y,s[j].x,s[j].y);
          a[i,j]:=r; a[j,i]:=r;
        end;
    end;
end;

PROCEDURE FindMinOstov;
var c,Mi,Mj,k,p,i,j:integer; Min:real;
begin
  LenOstov:=0;
  for i:=1 to N do Col[i]:=i;
  for k:=1 to N-1 do
    begin
      Min:=MaxInt; Mi:=i; Mj:=j;
      for i:=1 to N do
        for j:=1 to N do
          if (Col[i]<>Col[j]) and (A[i,j]<Min) then begin Min:=A[i,j]; Mi:=i; Mj:=j; end;
      Res[1,k]:=Mi; Res[2,k]:=Mj; LenOstov:=LenOstov+Min;
      c:=Col[Mj];
      for p:=1 to N do
      if Col[p]=c then Col[p]:=Col[Mi];
    end;
end;

BEGIN
  ReadData;
  FindMinOstov;
  writeln (lenostov:0:0);
END.
