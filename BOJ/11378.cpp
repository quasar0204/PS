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
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 1001;

int tc, cnt;
int n, m, k;
vector<int> adj[mxn];
bool c[mxn];
int d[mxn];

bool solve(int x) {
	for (auto w : adj[x]) {
		if (c[w]) continue;
		c[w] = true;

		if (d[w] == 0 || solve(d[w])) {
			d[w] = x;
			return true;
		}
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a;
		while (a--) {
			cin >> b;
			adj[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++) {
		fill(c, c + mxn, false);
		if (solve(i)) cnt++;
	}

	int res = 0;
	for (int i = 1; i <= n;) {
		if (res == k) break;

		fill(c, c + mxn, false);
		if (solve(i)) res++;
		else i++;
	}

	cout << cnt + res;
	//code end
	return 0;
}