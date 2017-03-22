#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MaxSide = 10;

int n, targetR, targetC;
vector<string> C, S; // Constraints, Slashes
vector<vector<bool>> vis;

bool dfs(int r, int c) {
	if (r == targetR && c == targetC) return true;
	if (vis[r][c]) return false;
	vis[r][c] = true;
	if (r < n && c < n && S[r][c] == '\\') if (dfs(r + 1, c + 1)) return true;
	if (r > 0 && c > 0 && S[r - 1][c - 1] == '\\') if (dfs(r - 1, c - 1)) return true;
	if (r > 0 && c < n && S[r - 1][c] == '/') if (dfs(r - 1, c + 1)) return true;
	if (r < n && c>0 && S[r][c - 1] == '/') if (dfs(r + 1, c - 1)) return true;
	return false;
}

// Is there a loop connecting intersections (r,c) and (tr,tc)?
bool loop(int r, int c, int tr, int tc) {
	vis = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
	targetR = tr;
	targetC = tc;
	return dfs(r, c);
}

void addCurrPoss(char s, char c, int &curr, int &poss) {
	if (s == c) curr++;
	else if (s == '.') poss++;
}

// Is it feasible to satisfy the constraint at intersection (r,c)?
bool feas(int r, int c) {
	int m = C[r][c];
	if (m == '.') return true;
	m -= '0';
	int curr = 0, poss = 0;
	if (r < n && c < n) addCurrPoss(S[r][c], '\\', curr, poss);
	if (r > 0 && c > 0) addCurrPoss(S[r - 1][c - 1], '\\', curr, poss);
	if (r > 0 && c < n) addCurrPoss(S[r - 1][c], '/', curr, poss);
	if (r < n && c>0) addCurrPoss(S[r][c - 1], '/', curr, poss);
	return curr <= m && m <= curr + poss;
}

bool canPut(int r, int c, char s) {
	if (s == '/' && loop(r, c + 1, r + 1, c)) return false;
	if (s == '\\' && loop(r, c, r + 1, c + 1)) return false;
	S[r][c] = s;
	bool can = (feas(r, c) && feas(r + 1, c) && feas(r, c + 1) && feas(r + 1, c + 1));
	S[r][c] = '.';
	return can;
}

bool put();

bool tryPut(int r, int c, char s) {
	S[r][c] = s;
	if (put()) return true;
	S[r][c] = '.';
	return false;
}

// Try to put a new line 
bool put() {
	// First set forced lines
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			if (S[r][c] == '.') {
				bool a = canPut(r, c, '/');
				bool b = canPut(r, c, '\\');
				if (a && !b) return tryPut(r, c, '/');
				if (!a && b) return tryPut(r, c, '\\');
				if (!a && !b) return false;
			}

	// If no forced lines try to set an arbitrary
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			if (S[r][c] == '.') {
				if (tryPut(r, c, '/')) return true;
				if (tryPut(r, c, '\\')) return true;
				return false;
			}

	// If nothing left we're done
	return true;
}

int main() {
	cin >> n;
	string s;
	getline(cin, s);
	C = vector<string>(n + 1);
	for (int r = 0; r <= n; r++) getline(cin, C[r]);
	S = vector<string>(n, string(n, '.'));
	put();
	for (int r = 0; r < n; r++) cout << S[r] << endl;
}
