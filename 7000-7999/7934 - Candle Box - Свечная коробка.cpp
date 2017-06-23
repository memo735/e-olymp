#include <assert.h>
#include <iostream>

int main() {
	int D, R, T;
	scanf("%d %d %d", &D, &R, &T);
	assert(1 <= D && D <= 20);
	assert(4 <= R && R < 1000);
	assert(0 <= T && T < 1000);
	for (int rita_age = 4; rita_age <= 100; ++rita_age) {
		int rita_should_have = rita_age * (rita_age + 1) / 2 - 6;
		if (rita_should_have > R) continue;
		int theo_age = rita_age - D;
		if (theo_age < 3) continue;
		int theo_had = theo_age * (theo_age + 1) / 2 - 3;
		if (theo_had < T) continue;
		int added = theo_had - T;
		if (rita_should_have + added == R) printf("%d\n", added);
	}
	return 0;
}
