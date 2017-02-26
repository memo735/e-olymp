#include <iostream>

using namespace std;

int main() {
	int h1, m1, s1, h2, m2, s2, h3, m3, s3, t1, t2;
	scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
	t1 = h1 * 3600 + m1 * 60 + s1;
	t2 = h2 * 3600 + m2 * 60 + s2;
	int d = (t2 - t1 + 3600 * 24) % (3600 * 24);
	h3 = d / 3600; d = d % 3600;
	m3 = d / 60;
	s3 = d % 60;
	printf("%02d:%02d:%02d\n", h3, m3, s3);
	return 0;
}
