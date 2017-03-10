#include <iostream>
#include <string.h>

using namespace std;

const int LINE_LENGTH = 50, MAX = 1001;

int F, D, repeatLength, pos[MAX];
char res[MAX];

void printRes(char * res) {
	int pos = 0, lineLength = 0;
	while (res[pos]) {
		printf("%c", res[pos++]);
		lineLength++;
		if (lineLength == LINE_LENGTH) {
			printf("\n");
			lineLength = 0;
		}
	}
	if (lineLength != 0) printf("\n");
}

void solve(int F, int D) {
	int resPos = 0;
	res[resPos++] = '.';
	pos[F] = 0;
	F *= 10;
	while (true) {
		int remainder = F%D, dRes = F / D;
		if (remainder == 0) {
			res[resPos++] = dRes + '0';
			printRes(res);
			printf("This expansion terminates.\n");
			return;
		}
		// repeated!  
		if (pos[remainder] != -1) {
			// printf("%d %d dRes %d\n", F, D, dRes);  
			res[resPos++] = dRes + '0';
			printRes(res);
			int repeatLength = resPos - pos[remainder] - 1;
			printf("The last %d digits repeat forever.\n", repeatLength);
			return;
		}
		pos[remainder] = resPos;
		res[resPos++] = dRes + '0';
		F = remainder * 10;
	}
}

int main() {
	while (scanf("%d %d", &F, &D) != EOF) {
		if (!F && !D) return 0;
		memset(res, 0, sizeof res);
		memset(pos, 0xff, sizeof pos);
		repeatLength = 0;
		solve(F, D);
	}
	return 0;
}
