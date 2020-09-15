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
const int mxn = 101;

int tc, cnt;
int n, m;

vector<vector<int>> adj;
vector<int> d;
vector<bool> c;

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
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		cnt = 0;

		adj.clear();
		adj.resize(m + 1);
		d.resize(n + 1);
		c.resize(n + 1);
		fill(all(d), 0);
		

		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			for (int k = a; k <= b; k++) {
				adj[i].push_back(k);
			}
		}
		
		for (int i = 1; i <= m; i++) {
			fill(all(c), false);
			if (solve(i)) cnt++;
		}

		cout << cnt << '\n';
	}

	//code end
	return 0;
}