#include <iostream>
#include <math.h>

using namespace std;

double mesafe(double xF, double yF, double xG, double yG)
{
	return sqrt((xF - xG)*(xF - xG) + (yF - yG)*(yF - yG));
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		double xA, yA, xB, yB, xC, yC, xD, yD, AB, BC, CD, AD, AC, BD;
		cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD;
		AB = mesafe(xA, yA, xB, yB);
		BC = mesafe(xB, yB, xC, yC);
		CD = mesafe(xC, yC, xD, yD);
		AD = mesafe(xA, yA, xD, yD);
		AC = mesafe(xA, yA, xC, yC);
		BD = mesafe(xB, yB, xD, yD);
		if (AB == BC && BC == CD && CD == AD)
		{
			if (AC == BD) cout << "Case " << i << ": Square" << endl;
			else cout << "Case " << i << ": Rhombus" << endl;
		}
		else
		{
			if (AB == CD && BC == AD) cout << "Case " << i << ": Rectangle" << endl;
			else cout << "Case " << i << ": Other" << endl;
		}
	}
	return 0;
}
