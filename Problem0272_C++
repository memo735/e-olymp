#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a_input, b_input, c_output;
vector <long long> a_vect, b_vect, c_vect;

void product_vect()
{
	for (int i = 0; i < 100000; i++) c_vect.push_back(0);
	for (int i = 0; i < a_vect.size(); i++)
		for (int j = 0; j < b_vect.size(); j++)
		{
			int ost = a_vect[i] * b_vect[j], index = i + j;
			while (ost > 0)
			{
				ost += c_vect[index];
				c_vect[index] = ost % 10000;
				ost /= 10000;
				index++;
			}
		}
}

int main()
{
	cin >> a_input;
	for (int i = 0; i < a_input.length() / 2; i++) swap(a_input[i], a_input[a_input.length() - i - 1]);
	while (a_input.length() % 4 != 0) a_input += "0";

	for (int i = 0; i < a_input.length() / 4; i++)
	{
		long long tmp = 0;
		tmp = a_input[i * 4] - 48 + (a_input[i * 4 + 1] - 48) * 10 + (a_input[i * 4 + 2] - 48) * 100 + (a_input[i * 4 + 3] - 48) * 1000;
		a_vect.push_back(tmp);
	}
	cin >> a_input;
	for (int i = 0; i < a_input.length() / 2; i++) swap(a_input[i], a_input[a_input.length() - i - 1]);
	while (a_input.length() % 4 != 0) a_input += "0";
	for (int i = 0; i < a_input.length() / 4; i++)
	{
		long long tmp = 0;
		tmp = a_input[i * 4] - 48 + (a_input[i * 4 + 1] - 48) * 10 + (a_input[i * 4 + 2] - 48) * 100 + (a_input[i * 4 + 3] - 48) * 1000;
		b_vect.push_back(tmp);
	}

	product_vect();

	bool first_zero = true, first = false;
	for (int i = c_vect.size() - 1; i >= 0; i--)
	{
		if (!first && c_vect[i] != 0)
		{
			cout << c_vect[i];
			first = true;
			first_zero = false;
		}
		else if (c_vect[i] != 0 || (c_vect[i] == 0 && !first_zero))
		{
			first_zero = false;
			if (c_vect[i] < 10) cout << "000";
			else if (c_vect[i] < 100) cout << "00";
			else if (c_vect[i] < 1000) cout << "0";
			cout << c_vect[i];
		}
	}
	if (first_zero) cout << "0";
	cout << endl;
}
