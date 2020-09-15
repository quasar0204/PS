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

int tc, cnt;
int n, m;
int ans[1001];
int indeg[1001];
vector<int> adj[1001];
void solve() {
	queue<pii> q;

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push({ i, 1 });
			ans[i] = 1;
		}
	}

	while (!q.empty()) {
		int now = q.front().first;
		int id = q.front().second;
		q.pop();

		for (int next : adj[now]) {
			indeg[next]--;

			if (indeg[next] == 0) {
				q.push({ next, id + 1 });
				ans[next] = id + 1;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}

	solve();

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}


	//code end
	return 0;
}