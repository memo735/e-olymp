var a:array[1..900, 1..900, 1..900] of integer; l, p, n, k, s, i, j, m, cavab, count:longint; OK:boolean;
begin
  readln (n);
  k:=1;s:=1;
  while s<n do
    begin
      inc(k); s:=k*k*k;
    end;
    
{--------- 1ci sira ----------}
  a[1,1,1]:=12;
  for i:=2 to k do a[1,i,1]:=8;
  for j:=2 to k do a[1,1,j]:=8;
  for i:=2 to k do
    for j:=2 to k do a[1,i,j]:=5;
    
{--------- 2..k sirasi ----------}
  for m:=2 to k do
    begin
      a[m,1,1]:=8;
      for i:=2 to k do a[m,i,1]:=5;
      for j:=2 to k do a[m,1,j]:=5;
      for i:=2 to k do
        for j:=2 to k do a[m,i,j]:=3;
    end;
    cavab:=0; count:=0; OK:=true;
    for m:=1 to k-1 do
      for i:=1 to k-1 do
        for j:=1 to k-1 do
          begin
            cavab:=cavab+a[m,i,j]; inc(count);
          end;

{------------------------------------}
  l:=n-count; j:=k; p:=1; s:=1;
  while s<l do
    begin
      inc(p); s:=p*p;
    end;
    if p>k-1 then p:=k-1;
    i:=1;
    while (i<=p) and OK do
      begin
        m:=1;
        while (m<=p) and OK do
          begin
            cavab:=cavab+a[m,i,j]; inc(count);
            if count=n then OK:=false;
            inc(m);
          end;
          inc(i);
      end;
{+++++++++++++++++++++++++++++++++++++++++}
  l:=n-count; i:=k; p:=1; s:=1;
  while s<l do
    begin
      inc(p); s:=p*p;
    end;
  if p>k-1 then p:=k-1;
  j:=1;
  while (j<=p) and OK do
    begin
      m:=1;
      while (m<=p) and OK do
        begin
          cavab:=cavab+a[m,i,j]; inc(count);
          if count=n then OK:=false;
          inc(m);
        end;
      inc(j);
    end;
{+++++++++++++++++++++++++++++++++++++++++}
  i:=k; j:=k; m:=1;
  while (m<k) and OK do
    begin
      cavab:=cavab+a[m,i,j]; inc(count);
      if count=n then OK:=false;
      inc(m);
    end;
{------------------------------------}
  l:=n-count; m:=k; p:=1; s:=1;
  while s<l do
    begin
      inc(p); s:=p*p;
    end;
  i:=1;
  while (i<=p) and OK do
    begin
      j:=1;
      while (j<=p) and OK do
        begin
          cavab:=cavab+a[m,i,j]; inc(count);
          if count=n then OK:=false;
          inc(j);
        end;
      inc(i);
    end;
{------------------------------------}
  if n=0 then writeln (0) else writeln (cavab);
end.
