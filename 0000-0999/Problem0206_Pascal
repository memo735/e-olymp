program Problem206;
var a : array[1..3,1..2] of LongInt;
n,i,o,k,w: LongInt;
begin
  readln(k,w);
  for i:=1 to 3 do read(a[i,1],a[i,2]);
  if (a[1,1]<=w) and (a[1,2]>=k) then inc(o);
  if (a[2,1]<=w) and (a[2,2]>=k) then inc(o);
  if (a[3,1]<=w) and (a[3,2]>=k) then inc(o);
  if (a[1,1]+a[2,1]<=w) and (a[1,2]+a[2,2]>=k) then inc(o);
  if (a[1,1]+a[3,1]<=w) and (a[1,2]+a[3,2]>=k) then inc(o);
  if (a[2,1]+a[3,1]<=w) and (a[2,2]+a[3,2]>=k) then inc(o);
  if (a[1,1]+a[3,1]+a[2,1]<=w) and (a[1,2]+a[3,2]+a[2,2]>=k) then inc(o);
  if o>=1 then writeln('YES') else writeln('NO');
end.
