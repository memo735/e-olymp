#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int n;
char c;

bool process(priority_queue<int> &q)
{
	while (!q.empty())
	{
		int v = q.top(); q.pop();
		queue<int> add;
		while (v--)
		{
			if (q.empty()) return false;
			if (q.top() != 1) add.push(q.top() - 1);
			q.pop();
		}
		while (!add.empty())
		{
			q.push(add.front());
			add.pop();
		}
	}
	return true;
}

int main() {
	//Читаем числа одной строки (одного теста). Когда после числа будет прочитан символ '\n',
	//произойдет обработка данных.Если ответ утвердительный, то выводим ok, иначе fail.
	while (scanf("%d%c", &n, &c) == 2)
	{
		pq.push(n);
		if (c == '\n')
		{
			printf(process(pq) ? "ok\n\n" : "fail\n\n");
			//Чистим очередь для ее использования в следующем тесте.
			while (!pq.empty()) pq.pop();
		}
	}
	return 0;
}
