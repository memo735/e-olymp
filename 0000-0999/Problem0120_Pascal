Const MaxDig=30; Osn=100000;
Type  Tlong=Array [0..MaxDig] of longint;
var a:array[0..100,-9..900] of Tlong; i, j, n, m, k:longint; temp1, temp2:Tlong;

Procedure WriteLong (t:Tlong);
Var i:Integer; s, ls:String;
Begin
  Str (Osn div 10, ls);
  Write (t[t[0]]);
  For i:=t[0]-1 Downto 1 Do
    Begin
      Str (t[i], s);
      While Length (s)< Length (ls) Do s:='0'+s; 
      Write (s);
    End;
End;

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

Procedure sublong(a,b:Tlong; var c:Tlong);
var k,i,p:longint;
begin
  fillchar(c,sizeof(c),0);
  if a[0]>b[0] then k := a[0] else k := b[0];
  p:=0;
  for i:=1 to k do
    begin
      c[i]:=a[i]-b[i]-p;
      if c[i]<0 then
        begin
          p:=1; inc(c[i],osn);
        end
      else p:=0;
    end;
  for i:=k downto 1 do
    if c[i]<>0 then break;
  c[0]:=i;
end;

begin
  readln (n, m);
  for i:=1 to n do
    begin
      a[i,1][0]:=1; a[i,1][1]:=1;
    end;
  for j:=1 to 9 do
    begin
      a[1,j][0]:=1; a[1,j][1]:=1;
    end;
  for i:=2 to n do
    for j:=2 to m do
      begin
        sumlongtwo(a[i,j-1],a[i-1,j],temp1);
        sublong(temp1,a[i-1,j-10], temp2);
        a[i,j]:=temp2;
      end;
  writelong (a[n,m]);
  writeln;
end.
