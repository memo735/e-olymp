#include <iostream>
using namespace std;

long long N, answer, M;

int main()
{
	cin >> N; M = 0;
	while (M*M < N) M++;
	M--;	
	answer += M * (M+1) * 2;
	answer += (N - M*M)*2;
	answer++;
	if (N - M*M > M) answer++;
	cout << answer << endl;
}
