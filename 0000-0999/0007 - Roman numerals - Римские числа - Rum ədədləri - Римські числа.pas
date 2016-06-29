TYPE DigStr = string[2];
CONST Digs:Array[1..13] of DigStr = ('I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M');
      Vals:Array[1..13] of longint = (1,4,5,9,10,40,50,90,100,400,500,900,1000);
VAR sum:longint; S, temp, st1, st2:string; c:char;

FUNCTION Dig(C:char):longint;
begin
  case C of
    'I':Dig:=1;
    'V':Dig:=5;
    'X':Dig:=10;
    'L':Dig:=50;
    'C':Dig:=100;
    'D':Dig:=500;
    'M':Dig:=1000;
  end;
end;

FUNCTION RomanToArab(var S:string):longint;
var Sum,i,Len:longint;
begin
  Sum:=0;
  i:=1; Len:=length(S);
  while i<Len do
  begin
    if Dig(S[i])<Dig(S[i+1]) then
      begin
        Sum:=Sum+Dig(S[i+1])-Dig(S[i]);
        i:=i+1;
      end
    else Sum:=Sum+Dig(S[i]);
    i:=i+1;
  end;
  if i=Len then Sum:=Sum+Dig(S[Len]);
  RomanToArab:=Sum;
end;

FUNCTION ArabToRoman(Num:longint):string;
var S:String; K,i:longint;
begin
  i:=13; S:='';
  K:=Num;
  while i<>0 do
    if K>=Vals[i] then
      begin
        K:=K-Vals[i];
        S:=S+Digs[i];
      end
    else dec(i);
  ArabToRoman:=S;
end;

BEGIN
  st1:='';
  read (c);
  while c<>'+' do
    begin
      st1:=st1+c;
      read (c);
    end;
  st2:='';
  while not(eoln) do
    begin
      read (c);
      st2:=st2+c;
    end;
  sum:=RomanToArab(st1)+RomanToArab(st2);
  writeln(ArabToRoman(sum));
END.
