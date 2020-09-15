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
const int mxn = 52;

int tc, cnt;
int n;
int c[mxn][mxn], f[mxn][mxn], visit[mxn];
int ans;
vector<int> adj[mxn];

void maxFlow(int start, int end) {
	while (true) {
		fill(visit, visit + mxn, -1);
		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : adj[now]) {
				
				if (visit[next] == -1 && c[now][next] - f[now][next] > 0) {
					q.push(next);
					visit[next] = now;
					if (next == end) break;
				}
			}
		}

		if (visit[end] == -1) break;

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
	cin >> n;

	int from, to;
	int cap;
	char a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> cap;
		if (a >= 'A' && a <= 'Z')
			a -= 'A';
		else
			a = a - 'a' + 26;

		if (b >= 'A' && b <= 'Z')
			b -= 'A';
		else
			b =  b - 'a' + 26;

		from = (int)a;
		to = (int)b;

		adj[from].push_back(to);
		adj[to].push_back(from);
		c[from][to] += cap;
		c[to][from] += cap;
	}

	maxFlow(0, 25);

	cout << ans;

	//code end
	return 0;
}