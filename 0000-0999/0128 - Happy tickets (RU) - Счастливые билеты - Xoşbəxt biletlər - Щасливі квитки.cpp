#include <iostream>

int main()
{
	int S, k = 0;
	std::cin >> S;
	for (int a = 0; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for (int c = 0; c < 10; c++)
				if (a + b + c == S) k++;
	std::cout << k*k << std::endl;
}
