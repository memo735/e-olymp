#include <iostream>
#include <math.h>
#include <stack>
#include <vector>

using namespace std;

vector<string> split(string s, char c)
{
	vector<string> res;
	int i = 0, j = s.find(c);
	while (j >= 0)
	{
		if (s[i] != c) res.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);
	}
	if (i < s.size()) res.push_back(s.substr(i));
	return res;
}

//Набор лексем в обратной польской записи задан в массиве строк tokens.
//Вычислим значение выражения в точке Value. Функция CheckIdentity
//возвращает 1, если полученное  значение равно нулю (0 в противном случае).
int CheckIdentity(vector<string> &tokens, double Value)
{
	stack<double> s;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "x") s.push(Value); else
			if (tokens[i] == "sin")
			{
				double v = s.top(); s.pop();
				s.push(sin(v));
			}
			else
				if (tokens[i] == "cos")
				{
					double v = s.top(); s.pop();
					s.push(cos(v));
				}
				else
					if (tokens[i] == "tan")
					{
						double v = s.top(); s.pop();
						s.push(tan(v));
					}
					else
						if (tokens[i] == "+")
						{
							double a = s.top(); s.pop();
							double b = s.top(); s.pop();
							s.push(a + b);
						}
						else
							if (tokens[i] == "-")
							{
								double a = s.top(); s.pop();
								double b = s.top(); s.pop();
								s.push(b - a);
							}
							else
								if (tokens[i] == "*")
								{
									double a = s.top(); s.pop();
									double b = s.top(); s.pop();
									s.push(a*b);
								}
	}
	double Result = s.top(); s.pop();
	if (fabs(Result) < 1e-7) return 1;
	return 0;
}

int n;
double Value;
char str[300];

int main() {
	//Читаем входную строку str, разбиваем ее на лексемы (разделителем является
	//пробел). Вычисляем значение функции, например, во всех точках x от 1 до 2
	//с шагом 0.02. Если для некоторого значения x результат окажется ненулевой,
	//то заданная на входе функция не является тождественно равной нулю.
	while (scanf("%d ", &n), n)
	{
		gets(str);
		vector<string> tokens = split(str, ' ');
		int flag = 1;
		for (Value = 1; Value <= 2; Value += 0.02) {
			if (!CheckIdentity(tokens, Value))
			{
				flag = 0;
				break;
			}
		}
		printf(flag ? "Identity\n" : "Not an identity\n");
	}
	return 0;
}
