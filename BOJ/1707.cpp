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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 20001;

int tc, cnt;
int n;
int v, e;

vector<vector<int>> adj;
int visit[mxn];

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= v; i++) {
		if (visit[i] != -1) continue;

		visit[i] = 0;
		q.push(i);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : adj[now]) {
				if (visit[next] == visit[now]) {
					return false;
				}

				if (visit[next] != -1)
					continue;

				visit[next] = 1 - visit[now];
				q.push(next);
			}
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	int a, b;
	while (tc--) {
		cin >> v >> e;
		adj.clear();
		adj.resize(v + 1);
		memset(visit, -1, sizeof(visit));

		while (e--) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if (bfs()) cout << "YES\n";
		else cout << "NO\n";

	}

	//code end
	return 0;
}