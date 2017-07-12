#include <iostream>
#include <map>

using namespace std;

int main() {
	map<char, int> attempts;
	int correct = 0, score = 0, submit;
	while (cin >> submit && submit != -1) {
		char p;
		string result;
		cin >> p >> result;
		attempts[p]++;
		if (result == "right") {
			correct++;
			score += submit + 20 * (attempts[p] - 1);
		}
	}
	cout << correct << " " << score << endl;
	return 0;
}
