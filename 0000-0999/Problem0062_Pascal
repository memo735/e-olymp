Const Osn=10000; MaxDig=2000;
Type TLong=Array [0..MaxDig] of longint;
Var p, r:Tlong; rez, t, max, ii, tt, code:integer; f:text; st:string;

Procedure ReadLong (var A:TLong);
Var ch:char; i:integer;
Begin
  Read (ch);
  While ch in ['0'..'9'] Do
    Begin
      For i:=A[0] DownTo 1 Do
        Begin
          A[i+1]:=A[i+1]+(A[i]*10) div Osn;
          A[i]:= (A[i]*10) mod Osn;
        End;
      A[1]:=A[1]+Ord(ch)-48;
      If A[A[0]+1]>0 Then Inc (A[0]);
      Read (ch);
    End;
End;

Procedure WriteLong (Const A:TLong);
Var ls, s:string; i:integer;
Begin
  Str (Osn div 10, ls);
  Write (A[A[0]]);
  For i:=A[0]-1 DownTo 1 Do
    Begin
      Str (A[i], s);
      While Length (s)<Length (ls) do s:='0'+s;
      Write (s);
    End;
  Writeln;
End;

Procedure Mul (A:TLong; k:integer; Var C:TLong);
Var i:integer;
Begin
  fillchar (c,maxdig,0);
  If k=0 Then Inc(C[0])
  Else
    Begin
      For i:=1 To A[0] Do
        Begin
          C[i+1]:=(Longint(A[i]*k)+C[i]) Div Osn;
          C[i]:=(Longint(A[i]*k)+C[i]) Mod Osn;
        End;
      If C[A[0]+1]>0 Then C[0]:=A[0]+1 Else C[0]:=A[0];
    End;
End;

function check(A, B:TLong) :boolean;
var ii:integer;
begin
  check:=false;
  ii:=0;
  while (a[ii]=b[ii]) and (ii<2001) do
    begin
      inc(ii);
    end;
  if ii=2001 then check:=true;
end;

BEGIN
  ReadLong(r);
  if (r[0]=1) and (r[1]=1) then rez:=1
  else
    begin
      p[0]:=1; p[1]:=1; rez:=1;
      repeat
        inc(rez);
        Mul (p,rez,p);
      until check(p, r);
    end;
  Writeln (rez);
END.
