var s:string; c:char; code, ln:word; flag:boolean;
    j, n, tt, p, max, rez, mm, temp:longint;

function proste(t:longint):boolean;
var s, i, k :longint;
begin
  proste:=false;
  if (t=0) or (t=1) then proste:=false
  else
    if t=2 then proste:=true
    else
      begin
        k:=0;
        for i:=2 to trunc(sqrt(t)) do if t mod i = 0 then k:=k+1;
        if k=0 then proste:=true;
      end;
end;

BEGIN
  s:=''; read(c);
  while c in ['0'..'9'] do
    begin
      s:=s+c; read (c);
    end;
  val (s, p, code);
  s:=''; read (c);
  while c in ['0'..'9'] do
    begin
      s:=s+c; read (c);
    end;
  ln:=length (s);
  val (s, n, code);
  s:='';
  for j:=1 to ln do s:=s+'9';
  val(s, mm, code);
  if (n>=7) and (mm=9) then rez:=-1
  else
    if (n>=97) and (mm=99) then rez:=-1
    else
      if (n>=997) and (mm=999) then rez:=-1
      else
        if (n>=9973) and (mm=9999) then rez:=-1
        else
          if (n>=99991) and (mm=99999) then rez:=-1
          else
            if (n>=999983) and (mm=999999) then rez:=-1
            else
              if (p=2) and (n<>2) then rez:=-1
              else
                if (p>2) then
                  begin
                    tt:=n;
                    while (not(proste(tt))) and (tt<mm) and (tt<n+p) do begin inc (tt); end;
                    j:=tt+1;
                    flag:=true;
                    while (flag) and (j<mm) and (j<tt+p) do
                      begin
                        if proste (j) then
                          begin
                            rez:=j-tt-1; flag:=false;
                          end
                        else inc (j);
                  end;
  if (j=tt+p) or (j=mm) then rez:=-1;
  end
  else rez:=-1;
  writeln (rez);
END.
