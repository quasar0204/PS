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
vector<int> ans;
vector<int> adj[32001];
int indeg[32001];


void solve() {
	priority_queue<int> pq;

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();
		ans.push_back(now);

		for (int next : adj[now]) {
			if (--indeg[next] == 0) {
				pq.push(-next);
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

	for (auto x : ans)
		cout << x << ' ';
	//code end
	return 0;
}