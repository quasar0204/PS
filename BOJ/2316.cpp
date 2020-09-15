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


const int mxn = 400;
int tc, cnt;
int n, p;
vector<int> adj[2*mxn+1];
int c[2 * mxn + 1][2 * mxn + 1], f[2 * mxn + 1][2 * mxn + 1], visit[2 * mxn + 1];
int ans;

void maxFlow(int start, int end) {
	while (true) {
		fill(visit, visit + 2 * mxn + 1, -1);
		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : adj[now]) {
				if (visit[next] == -1 && c[now][next] - f[now][next] > 0) {
					q.push(next);
					visit[next] = now;

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
	cin >> n >> p;

	int from, to;

	for (int i = 1; i <= n; i++) {
		adj[2 * i].push_back(2 * i - 1);
		adj[2 * i - 1].push_back(2 * i);
		c[2 * i - 1][2 * i] = 1;
	}

	for (int i = 0; i < p; i++) {
		cin >> from >> to;

		adj[2 * from].push_back(2 * to - 1);
		adj[2 * to - 1].push_back(2 * from);

		adj[2 * to].push_back(2 * from - 1);
		adj[2 * from - 1].push_back(2 * to);


		c[2 * from][2 * to - 1] = 1;
		c[2 * to][2 * from - 1] = 1;

	}

	maxFlow(2, 3);

	cout << ans;
	//code end
	return 0;
}