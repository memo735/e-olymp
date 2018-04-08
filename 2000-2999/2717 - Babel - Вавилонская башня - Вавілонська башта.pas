var a: array[1..200, 1..200] of integer;
	u: array[1..200] of boolean;
	i, j, n, m, ans, k: integer;

procedure dfs(v: integer); //процедура обхода в глубину
var i0: integer;
begin
	if v > 50 then
	begin
		u[v]:=true;
		inc(ans);
	end;
	for i0:=1 to 50+n do
	if (not u[i0])and(a[v,i0]=1) then dfs(i0);    
end;

begin
	read(n);
	fillchar(a, sizeof(a), 0);
	for i:=1 to n do //перебираем людей
	begin
		read(m); //считываем количество языков, которые знает человек 
		for j:=1 to m do //заполняем матрицу смежности
		begin
			read(k); //считываем номер языка
			a[k, 50+i]:=1;
			a[50+i,k]:=1;
		end;
	end;
	fillchar(u, sizeof(u), false);
	ans:=0;
	dfs(51); //запускаем обход в глубину
	writeln(ans);
end.
