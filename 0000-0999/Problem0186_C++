#include <iostream>
#include <cmath>

double n, k = 0, x, q, w, e;

int main(){
	scanf("%lf", &n);
	q = log10(2.0);
	w = log10(n);
	e = log10(n + 1);
	while (true){
		x = k*q - w;
		if (x >= 0 && floor(x) > k*q - e) break;
		k++;
	}
	printf("%.0f", k);
}
