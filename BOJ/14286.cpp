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


const int mxn = 500;
int tc, cnt;
int n, m;
vector<int> adj[mxn + 1];
int visit[mxn + 1], c[mxn + 1][mxn + 1], f[mxn + 1][mxn + 1];
int ans;

void maxFlow(int start, int end) {
	while (true) {
		queue<int> q;
		q.push(start);
		fill(visit, visit + mxn + 1, -1);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : adj[now]) {

				if (visit[next] == -1 && c[now][next] - f[now][next] > 0) {
					visit[next] = now;
					q.push(next);
					if (next == end)
						break;
				}
			}
		}

		if (visit[end] == -1)
			break;

		int flow = INF;

		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}

		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}

	ans += flow;
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	int from, to, val;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> val;

		adj[from].push_back(to);
		c[from][to] = val;
		adj[to].push_back(from);
		c[to][from] = val;
	}

	cin >> from >> to;

	maxFlow(from, to);

	cout << ans;

	//code end
	return 0;
}