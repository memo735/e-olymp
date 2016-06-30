Const MaxN = 100002; LgMaxN = 20; MaxM = 500002;
Type TList = ^Plist;
PList = Record
  V, NumEdge: LongInt; Next: TList;
        End;

Var N,M,Root,K,KolKomp,Time: LongInt;
    Most: Array[1..MaxM] Of Boolean;
    Us: Array[1..MaxN] Of Boolean;
    TreeEdges,GraphEdges: Array[1..MaxN] Of TList;
    Komp,Len,TimeIn,MaxTimeIn,MinTimeIn: Array[1..MaxN] Of LongInt;
    Pr: Array[1..MaxN,0..LgMaxN] Of LongInt;

Function Predok(Num1,Num2: LongInt): Boolean;
Begin
  If (TimeIn[Num2] >= TimeIn[Num1]) And (TimeIn[Num2] <= MaxTimeIn[Num1]) Then Predok:= True Else Predok:= False;
End;

Function LCA(Num1,Num2: LongInt): LongInt;
Var i: LongInt;
Begin
  If (Predok(Num1,Num2)) Then LCA:= Num1
  Else
    If (Predok(Num2,Num1)) Then LCA:= Num2
    Else
      Begin
        For i:= LgMaxN DownTo 0 Do
          If (Not (Predok(Pr[num1,i],num2))) Then num1:= Pr[num1,i];
        LCA:= Pr[num1,0];
      End;
End;

Procedure Solve(Num1,Num2: LongInt);
Var j: LongInt;
Begin
  j:= LCA(Num1,Num2);
  Writeln(Len[j]);
End;

Procedure DFS(Num,Pr: LongInt; GoOnMosts: Boolean); {DFS ¤«п ­ е®¦¤Ґ­Ёп ¬®бв®ў Ё Є®¬Ї®­Ґ­в бўп§ ­®бвЁ Ї®б«Ґ Ёе г¤ «Ґ­Ёп}
Var Temp: TList; Fl: Boolean;
Begin
  Inc(Time);
  TimeIn[Num]:= Time;
  MinTimeIn[num]:= Time;
  Us[Num]:= True;
  Temp:= GraphEdges[num];
  Komp[num]:= KolKomp;
  While (Temp <> Nil) Do
    Begin
      If (GoOnMosts) And (Most[Temp^.NumEdge]) Then Fl:= False Else Fl:= True;
      If (Not Us[Temp^.V]) And (Fl) Then
        Begin
          DFS(Temp^.V,Num,GoOnMosts);
          If Not GoOnMosts Then
            Begin
              If MinTimeIn[Temp^.V] > TimeIn[Num] Then Most[Temp^.NumEdge]:= True;
              If MinTimeIn[Temp^.V] < MinTimeIn[Num] Then MinTimeIn[num]:= MinTimeIn[Temp^.V];
            End;
        End
      Else
        If (Fl) Then
          If (Temp^.V <> Pr) Then
            If TimeIn[Temp^.V] < MinTimeIn[Num] Then MinTimeIn[num]:= TimeIn[Temp^.V];
        Temp:= Temp^.Next;
    End;
End;

Procedure AddTreeEdge(A,B: LongInt);
Var x: TList;
Begin
  New(X);
  X^.V:= B;
  X^.Next:= TreeEdges[a];
  TreeEdges[a]:= X;
End;

Procedure DFSTree(Num,Predok,L: LongInt);
Var Temp: TList;
Begin
  Temp:= TreeEdges[Num];
  Us[num]:= True;
  Len[num]:= L;
  Pr[Num,0]:= Predok;
  Inc(Time);
  TimeIn[Num]:= Time;
  MaxTimeIn[Num]:= Time;
  While (Temp <> Nil) Do
    Begin
      If (Not Us[Temp^.V]) Then
        Begin
          DFSTree(Temp^.V,Num,L+1);
          If MaxTimeIn[Temp^.V] > MaxTimeIn[Num] Then MaxTimeIn[Num]:= MaxTimeIn[Temp^.V];
        End;
      Temp:= Temp^.Next;
    End;
End;

Procedure PreProcess;
Var i,j: LongInt; Temp: TList;
Begin
  FillChar(Us,SizeOf(Us),False);
  DFS(Root,Root,False);
  FillChar(Us,SizeOf(Us),False);
  FillChar(Komp,SizeOf(Komp),0);
  KolKomp:= 0;
  For i:= 1 To N Do
    If (Not Us[i]) Then
      Begin
        Inc(KolKomp);
        DFS(i,i,True);
      End;

  For i:= 1 To N Do
    Begin
      Temp:= GraphEdges[i];
      While (Temp <> Nil) Do
        Begin
          If (Most[Temp^.NumEdge]) Then
            Begin
              AddTreeEdge(Komp[Temp^.v],Komp[i]);
              AddTreeEdge(Komp[i],Komp[Temp^.v]);
            End;
          Temp:= Temp^.Next;
        End;
    End;

  FillChar(TimeIn,SizeOf(TimeIn),0);
  FillChar(MaxTimeIn,SizeOf(MaxTimeIn),0);
  Time:= 0;
  FillChar(Pr,SizeOf(Pr),0);
  FillChar(Us,SizeOf(Us),False);
  FillChar(Len,SizeOf(Len),0);
  DFSTree(Komp[Root],Komp[Root],0);
  For j:= 1 to LgMaxN Do
    For i:= 1 to KolKomp Do
      If Us[i] Then Pr[i,j]:= Pr[Pr[i,j-1],j-1];
End;

Procedure AddEdge(A,B,C: LongInt);
Var x: TList;
Begin
  New(X);
  X^.V:= B;
  X^.Next:= GraphEdges[a];
  X^.NumEdge:= C;
  GraphEdges[a]:= X;
End;

Var i,a,b: LongInt;
Begin
  FillChar(Most,SizeOf(Most),False);
  Read(N,M);
  Read(Root);
  For i:= 1 To M Do
    Begin
      Read(a,b);
      AddEdge(a,b,i);
      AddEdge(b,a,i);
    End;
  PreProcess;
  Read(K);
  For i:= 1 to K Do
    Begin
      Read(a,b);
      Solve(Komp[a],Komp[b]);
    End;
End.
