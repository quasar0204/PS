#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 300001;

int tc, cnt;
int n, k;

int p[mxn];
int num[mxn];
string str;

int root(int x) {
	if (p[x] == x) return x;
	return p[x] = root(p[x]);
}

void merg(int u, int v) {
	u = root(u), v = root(v);
	if (u != v) p[u] = v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		cin >> str;
		memset(num, -1, sizeof(num));
		for (int i = 1; i <= n; i++) p[i] = i;

		for (int i = 1; i <= n - k; i++) merg(i, i + k);

		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (str[i - 1] != '?') {
				if (num[root(i)] == -1) {
					num[root(i)] = str[i - 1] - '0';
				}
				else {
					if (num[root(i)] != (str[i - 1] - '0')) {
						flag = false;
						break;
					}
				}
			}
			if (!flag) break;
		}
		if (flag) {
			int n1 = 0, n0 = 0;
			for (int i = 1; i <= k; i++) {
				if (num[root(i)] == 0) n0++;
				else if (num[root(i)] == 1) n1++;
			}
			if (n1 <= k / 2 && n0 <= k / 2) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else cout << "NO\n";
		
	}
	return 0;
}
