const a:array[1..168] of integer = (2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
                                    179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,
                                    367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,
                                    571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,
                                    773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997);
Const MaxDig=3000; Osn=1000000;
Type  Tlong=Array [0..MaxDig] of longint;
var m:integer; od, x, rez:tlong; i, p, k:longint;

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

Procedure sublong(a,b:Tlong; var c:Tlong);
var k,i,p:longint;
begin
  fillchar(c,sizeof(c),0);
  if a[0]>b[0] then k := a[0] else k := b[0];
  p:=0;
  for i:=1 to k do
    begin
      c[i]:=a[i]-b[i]-p;
      if c[i]<0 then begin p:=1; inc(c[i],osn); end else p:=0;
    end;
  for i:=k downto 1 do if c[i]<>0 then break;
  c[0]:=i;
end;

begin
  readln (m);
  od[0]:=1; od[1]:=1;
  i:=1; x[0]:=1; x[1]:=1;
  while a[i]<=m do
    begin
      p:=a[i];
      repeat p:=p*a[i];
      until p>=m;
      if p>m then p:=p div a[i];
      mul(x,p,rez);
      x:=rez;
      i:=i+1;
    end;
  sublong(x,od,rez);
  writelong(rez);
  WRITELN;
end.
