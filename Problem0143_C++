#include <iostream>
#include <math.h>
using namespace std;

pair <int, int> A, B, C, O;

float Len(pair <int, int > X, pair <int, int > Y)
{
	return sqrtf((X.first - Y.first)*(X.first - Y.first) + (X.second - Y.second, 2)*(X.second - Y.second, 2));
}

float S(pair <int, int > X, pair <int, int > Y, pair <int, int > Z)
{
	float P, XY, XZ, YZ;
	XY = Len(X, Y);
	XZ = Len(X, Z);
	YZ = Len(Y, Z);
	P = (XY + XZ + YZ) / 2;
	float a = sqrtf(2);
	return sqrtf(P * (P - XY) * (P - XZ) * (P - YZ));
}

int main()
{
	cin >> O.first >> O.second >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
	int X, Y, Z;
	X = (A.first - O.first) * (B.second - A.second) - (B.first - A.first) * (A.second - O.second);
	Y = (B.first - O.first) * (C.second - B.second) - (C.first - B.first) * (B.second - O.second);
	Z = (C.first - O.first) * (A.second - C.second) - (A.first - C.first) * (C.second - O.second);

	if ((X >= 0 && Y >= 0 && Z >= 0) || (X <= 0 && Y <= 0 && Z <= 0)) cout << 1 << endl;
	else cout << 0 << endl;
}
