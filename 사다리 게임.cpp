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

typedef struct {
	int v;
	bool t;
} check;

int tc, cnt;
int n, k, m;
const int mxn = 9001;
vector<vector<int>> adj;
int last[1501];
check chk[1501][mxn];
bool visit[mxn];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';
		cin >> n >> k >> m;

		adj.clear();
		adj.resize(mxn);
		memset(chk, -1, sizeof(chk));

		for (int i = 1; i <= n; i++)
			last[i] = i;

		int node = n + 1;
		int from, to;
		for (int i = 0; i < k; i++) {
			cin >> from >> to;
			adj[last[from]].push_back(node);
			last[from] = node++;
			adj[last[to]].push_back(node);
			last[to] = node++;
			adj[node - 2].push_back(node - 1);
			adj[node - 1].push_back(node - 2);
		}

		for (int i = 1; i <= n; i++) {
			adj[last[i]].push_back(node);
			last[i] = node++;
		}

		for (int start = 1; start <= n; start++) {

			memset(visit, false, sizeof(visit));
			q.push(start);
			chk[start][start].v = 0;

			while (!q.empty()) {
				int now = q.top();
				q.pop();

				if (visit[now])
					continue;

				visit[now] = true;

				if (adj[now].size() == 1) {
					chk[start][adj[now][0]].v = chk[start][now].v;
					if (!visit[adj[now][0]]) {
						q.push(adj[now][0]);
					}
				}
				else if (adj[now].size() == 2) {
					if ((!visit[adj[now][0]]) && (chk[start][adj[now][0]].v == chk[start][now].v)) {
						chk[start][now].t = false;
						chk[start][adj[now][0]].t = false;
					}
					else if ((chk[start][adj[now][0]].v == -1) || (chk[start][adj[now][0]].v > chk[start][now].v)) {
						chk[start][adj[now][0]].t = false;
						chk[start][adj[now][0]].v = chk[start][now].v;
					}
					else if (chk[start][now].v > chk[start][adj[now][0]].v) {
						chk[start][now].v = chk[start][adj[now][0]].v;
						chk[start][now].t = false;
					}

					if (chk[start][now].t == false) {
						chk[start][adj[now][1]].v = chk[start][now].v;
					}
					else {
						chk[start][adj[now][1]].v = chk[start][now].v + 1;
					}
					if (!visit[adj[now][0]])
						q.push(adj[now][0]);

					if (!visit[adj[now][1]])
						q.push(adj[now][1]);
				}
			}
		}

		lint ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> from >> to;
			ans += chk[from][last[to]].v;
		}

		cout << ans << '\n';

	}

	return 0;
}