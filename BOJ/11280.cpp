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
const int mxn = 10000*2+2;

int tc, cnt;
int n, m, idx;
vector<int> adj[mxn];
int parent[mxn];
bool finished[mxn];
stack<int> st;
vector<vector<int>> scc;

int findSCC(int x) {
	parent[x] = ++idx;
	st.push(x);

	int p = parent[x];

	for (int y : adj[x]) {
		if (parent[y] == 0)
			p = min(p, findSCC(y));
		else if (!finished[y])
			p = min(p, parent[y]);
	}

	if (p == parent[x]) {
		vector<int> tmp;
		while (true) {
			int t = st.top();
			st.pop();

			tmp.push_back(t);
			finished[t] = true;

			if (t == x) {
				scc.push_back(tmp);
				break;
			}
		}
	}

	return p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		int p = x < 0 ? -2 * x : 2 * x;
		int q = y < 0 ? -2 * y : 2 * y;
		adj[x < 0 ? p : p + 1].push_back(y < 0 ? q + 1 : q);
		adj[y < 0 ? q : q + 1].push_back(x < 0 ? p + 1 : p);
	}

	for (int i = 2; i <= 2 * n + 1; i++)
		if (parent[i] == 0)
			findSCC(i);

	for (int i = 1; i <= n; i++) {
		if (parent[2 * i] == parent[2 * i + 1]) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	//code end
	return 0;
}