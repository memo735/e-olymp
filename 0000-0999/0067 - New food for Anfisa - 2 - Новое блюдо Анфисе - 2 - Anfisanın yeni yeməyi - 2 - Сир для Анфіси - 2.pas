Const NMax = 30;
Type Digit = 0..9; DlChislo = Array[1..Nmax] Of Digit;
Var S : String; M, N, R, F, K : DlChislo; I, MaxF : Word; Logic : Boolean; c:char;

Procedure Zero(Var A : DlChislo);
Var I : Integer;
Begin
  For I := 1 To NMax Do A[I] := 0;
End;
  
Function Dlina(C : DlChislo) : Integer;
Var I : Integer;
Begin
  I := NMax;
  While (I > 1) And (C[I] = 0) Do I := I - 1;
  Dlina := I
End;

Procedure Print(A : DlChislo);
Var I : Integer;
Begin
  For I := Dlina(A) DownTo 1 Do Write(A[I] : 1);
  WriteLn;
End;
  
Procedure Translate(S : String; Var A : DlChislo; Var OK : Boolean);
Var I : Word;
Begin
  Zero(A); I := Length(S); OK := True;
  While (I >= 1) And OK Do
    Begin
      If S[I] In ['0'..'9'] Then A[Length(S) - I+ 1] := Ord(S[I]) - 48 Else OK := False;
      I := I - 1
    End
End;

Procedure Multiplication(A, B : DlChislo; Var C : DlChislo);
Var I, J : Integer; P : Digit; VspRez : 0..99;
Begin
  Zero(C);
  For I := 1 To Dlina(A) Do
    Begin
      P := 0;
      For J := 1 To Dlina(B) Do
        Begin
          VspRez := A[I] * B[J] + P + C[I + J - 1];
	        C[I + J - 1] := VspRez Mod 10;
	        P := VspRez Div 10
	      End;
      C[I + J] := P
    End
End;
  
Begin
  s:=''; read(c);
  while c in ['0'..'9'] do begin s:=s+c; read (c); end;
  Translate(S, M, Logic);
  s:=''; read(c);
  while c in ['0'..'9'] do begin s:=s+c; read (c); end;
  Translate(S, N, Logic);
  s:=''; read(c);
  while c in ['0'..'9'] do begin s:=s+c; read (c); end;
  Translate(S, K, Logic);
  Multiplication(M, N, R);
  Multiplication(R, K, R);
  i:=1;
  while not(r[i]-1>=0) do begin r[i]:=9; i:=i+1; end;
  r[i]:=r[i]-1;
  Print(R);
End.
