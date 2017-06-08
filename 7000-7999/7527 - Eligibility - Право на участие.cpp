#include <stdio.h>

int main() {
	int n, courses, y1, m1, d1, y2, m2, d2;
	char name[31];
	scanf("%d\n", &n);
	while (n--)
	{
		scanf("%s %d/%d/%d %d/%d/%d %d", name, &y1, &m1, &d1, &y2, &m2, &d2, &courses);
		if (y1 >= 2010 || y2 >= 1991) printf("%s eligible\n", name);
		else printf(courses < 41 ? "%s coach petitions\n" : "%s ineligible\n", name);
	}
}
