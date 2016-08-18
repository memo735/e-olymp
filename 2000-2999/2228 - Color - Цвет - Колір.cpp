#include<cstdio> 
#include<vector>

using namespace std;

const int maxn = 1 << 15;
vector<pair<int, int> >v;
int n, mod, cnt = 0, prime[maxn];

int phi(int x)
{
	int a = x;
	for (int i = 0; i < cnt; i++)
	{
		int &p = prime[i];
		if (p*p > x) break;
		if (x%p == 0)
		{
			while (x%p == 0) x /= p;
			a -= a / p;
		}
	}
	if (x > 1) a -= a / x;
	return a%mod;
}

int pow(int x)
{
	int ans = 1, base = n%mod;
	while (x)
	{
		if (x & 1) ans = ans*base%mod;
		base = base*base%mod; x >>= 1;
	}
	return ans;
}

int dfs(int pos, int cur)
{
	int ans = phi(n / cur)*pow(cur - 1) % mod;
	while (pos < v.size())
	{
		int nxt = cur;
		for (int i = 0; i < v[pos].second; i++)
		{
			nxt *= v[pos].first;
			ans = (ans + dfs(pos + 1, nxt)) % mod;
		}
		pos++;
	}
	return ans;
}

void read(int &d)
{
	char ch;
	while (ch = getchar(), ch < 48 || ch > 57); d = ch - 48;
	while (ch = getchar(), ch > 47 && ch < 58) d = d * 10 + ch - 48;
}

void write(int d)
{
	if (d == 0){ puts("0"); return; }
	char str[6]; str[5] = 0; int i;
	for (i = 4; d; i--) str[i] = d % 10 + 48, d /= 10;
	puts(str + i + 1);
}

int main()
{
	int t, vis[maxn];
	for (int i = 2; i < maxn; i++)
		if (!vis[i])
		{
			prime[cnt++] = i;
			for (int j = i*i; j < maxn; j += i) vis[j] = 1;
		}

	read(t);
	while (t--)
	{
		read(n), read(mod);
		v.clear(); int x = n;
		for (int i = 0; i < cnt; i++)
		{
			int num, &p = prime[i];
			if (p*p > x) break;
			if (x%p) continue;
			for (num = 0; x%p == 0; num++) x /= p;
			v.push_back(make_pair(p, num));
		}
		if (x > 1) v.push_back(make_pair(x, 1));
		write(dfs(0, 1));
	}
	return 0;
}
