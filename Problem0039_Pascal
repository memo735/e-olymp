Const MaxDig=80; Osn=10000;
Type  Tlong=Array [0..MaxDig] of longint;
Var a1, a2, od, sum1, c, sum, ss: Tlong;
    s, n, j, i1, r, m, ip: Integer;

Procedure Readlong (var q:Tlong);
var i:longint; ch:char;
begin
  fillchar (q, sizeof(q), 0);
  repeat read (ch);
  until ch in ['0'..'9'];
  while ch in ['0'..'9'] do
    begin
      for i:=q[0] downto 1 do
        begin
          q[i+1]:=q[i+1]+q[i]*10 div osn;
          q[i]:=q[i]*10 mod osn;
        end;
      q[1]:=q[1]+ord(ch)-ord('0');
      if q[q[0]+1]>0 then inc(q[0]);
      read(ch);
    end;
end;

procedure poriv (x, y:Tlong;var r1, r2:integer);
var i:longint;
begin
  r1:=0; r2:=0;
  if x[0]=y[0] then
    begin
      i:=x[0];
      while (x[i]=y[i]) and (i>=1) do dec(i);
      if i=0 then begin r1:=1; exit; end
      else
        if x[i]<y[i] then begin r2:=1; exit; end;
        end
        else
          begin
            if x[0]<y[0] then
              begin r2:=1; exit; end
          end;
    end;

Procedure WriteLong (t:Tlong);
Var i:Integer; s, ls:String;
Begin
  Str (Osn div 10, ls);
  Write (t[t[0]]);   {vyved starsh cifr}
  For i:=t[0]-1 Downto 1 Do
    Begin
      Str (t[i], s);
      While Length (s)< Length (ls) Do s:='0'+s;  {dopovnen nuliv}
      Write (s);
    End;
  writeln;
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

function eq (a, b:Tlong):boolean;
var i:integer;
begin
  eq:=false;
  if a[0]=b[0] then
  begin
    i:=1;
    while (i<=a[0]) and (a[i]=b[i]) do inc(i);
    eq:=(i=a[0]+1);
  end;
end;

function more (a,b:Tlong):boolean;
var i:integer;
begin
  if a[0]<b[0] then more:=false
  else
    if a[0]>b[0] then more:=true
    else
      begin
        i:=a[0];
        while (i>0) and (a[i]=b[i]) do dec(i);
        if i=0 then more:=false
        else
          if a[i]>b[i] then more:=true
          else more:=false;
      end;
end;

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
          p:=1;
          inc(c[i],osn);
        end
      else p:=0;
    end;
  for i:=k downto 1 do if c[i]<>0 then break;
  c[0]:=i;
end;

BEGIN
  read (s, n);
  FillChar (c, Sizeof (c), 0);
  readlong (c);
  od[0]:=1; od[1]:=1;
  a1[0]:=1; a1[1]:=s;
  a2[0]:=1; a2[1]:=s;
  if (n=1) then
    begin
      if eq(a1, c) then begin ss[0]:=0; writelong (ss); halt; end;
      if more (a1, c) then begin sublong(a1,c,ss); writelong (ss); halt; end
      else begin sublong(c,a1,ss); writelong (ss); halt; end;
    end;
  if (n=2) then
    begin
      sumlongtwo (a1, a2, sum);
      if eq(sum, c) then begin ss[0]:=0; writelong (ss); halt; end;
      if more (sum, c) then begin sublong(sum,c,ss); writelong (ss); halt; end
      else begin sublong(c,sum,ss); writelong (ss); halt; end;
    end;
  for j:=3 to n do
    begin
      sumlongtwo (a1, a2, sum1);
      sumlongtwo (sum1, od, sum);
      a1:=a2; a2:=sum;
    end;
  if eq(sum, c) then begin ss[0]:=0; writelong (ss); halt; end;
  if more (sum, c) then begin sublong(sum,c,ss); writelong (ss); halt; end
  else begin sublong(c,sum,ss); writelong (ss); halt; end;
END.
