#include <iostream>

int main()
{
	long time = 0, h, m, s;
	std::cin >> h >> m >> s;
	time -= 3600 * h + 60 * m + s;
	std::cin >> h >> m >> s;
	time += 3600 * h + 60 * m + s;
	s = time % 60; time /= 60;
	m = time % 60; time /= 60;
	h = time;
	std::cout << h << " " << m << " " << s << "\n";
}
