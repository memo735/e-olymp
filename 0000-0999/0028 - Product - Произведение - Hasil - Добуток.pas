Const MaxDig=100;
      Osn=10000000000;
Type  Tlong=Array [0..MaxDig] of int64;
Var a, b, c, rez: Tlong; n, j, i1, r, m, ip: integer; p,k, ii:longint; f:text;

Procedure Readlong (var q:Tlong);
var i:longint; ch:char;
begin
  fillchar (q, sizeof(q), 0);
  k:=0;
  repeat
    read (ch);
  until ch in ['0'..'9'];
  while ch in ['0'..'9'] do
    begin
      for i:=q[0] downto 1 do
        begin
          q[i+1]:=q[i+1]+q[i]*10 div osn;
          q[i]:=q[i]*10 mod osn;
        end;
      inc(k);
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
        if x[i]<y[i] then begin r2:=1;exit; end;
      end
        else
          begin
            if x[0]<y[0] then begin r2:=1; exit; end
          end;
end;

Procedure Mul (t:Tlong; k:longint; var s:Tlong);
var i:longint;
begin
  fillchar (s, sizeof(s), 0);
  if k=0 then inc(t[0])
  else
    for i:=1 to t[0] do
      begin
        s[i+1]:=(t[i]*k+s[i]) div osn;
        s[i]:=(t[i]*k+s[i]) mod osn;
      end;
    if s[t[0]+1]=0 then s[0]:=t[0] else s[0]:=t[0]+1;
end;

BEGIN
  FillChar (c, Sizeof (c), 0);
  readlong (c);
  if k>800 then j:=1200 else j:=2;
  repeat
    a[0]:=1; a[1]:=1;
    i1:=j; r:=0; m:=1; ip:=j;
    while (r=0) and (m=1) do
      begin
        mul (a,i1,b); a:=b;
        poriv(b,c,r,m); i1:=i1+1;
      end;
    j:=j+1;
  until r=1;
  writeln (ip,' ',i1-1);
END.
