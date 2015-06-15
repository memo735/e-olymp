const a:array [0..30] of longint =(1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
                                   2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824);
var n, i:longint;

function count (m:longint):longint;
begin
  if (m=4) or (m=2) or (m=1) or (m=0) then count:=1
  else
    if m=3 then count:=2
    else
      if m<(a[i]+a[i+1]) div 2 then begin dec(i); count:=count(m-a[i]); end
      else begin dec(i); count:=2*count(m-a[i+1]); end;
end;

begin
  readln (n);
  for i:=1 to 30 do
    if n=a[i] then begin writeln (1); halt; end;
  i:=1;
  while n>a[i] do inc (i);
  dec(i);
  writeln (count (n));
end.
