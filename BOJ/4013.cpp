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
const int mxn = 500001;

int tc, cnt;
int v, e;
int id;
int idx;
int money[mxn];
int scc_money[mxn];
int parent[mxn];
int node[mxn];
int dp[mxn];
bool visit[mxn];
vector<bool> res;
stack<int> st;
vector<vector<int>> adj;
vector<vector<int>> SCC;
vector<set<int>> scc_adj;
int indeg[mxn];

int make_scc(int x) {
	parent[x] = ++id;
	st.push(x);

	int ret = parent[x];
	for (int y : adj[x]) {
		if (parent[y] == 0)
			ret = min(ret, make_scc(y));
		else if (node[y] == -1)
			ret = min(ret, parent[y]);
	}

	if (ret == parent[x]) {
		vector<int> scc;
		while (true) {
			int t = st.top();
			st.pop();

			scc.push_back(t);
			node[t] = idx;
			scc_money[idx] += money[t];

			if (t == x) {
				SCC.push_back(scc);
				break;
			}
		}
		idx++;
	}

	return ret;
}

int solve(int start) {
	queue<int> q;
	q.push(start);

	visit[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : scc_adj[now]) {
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}

	for (int i = 0; i < idx; i++) {
		if (!visit[i] && !indeg[i]) {
			q.push(i);
			visit[i] = true;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : scc_adj[now]) {
			indeg[next]--;
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}



	int ret;

	if (res[start] == true)
		ret = scc_money[start];
	else
		ret = 0;

	dp[start] = scc_money[start];

	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : scc_adj[now]) {
			indeg[next]--;

			if (indeg[next] == 0)
				q.push(next);

			dp[next] = max(dp[now] + scc_money[next], dp[next]);
			if (res[next] == true) {
				ret = max(ret, dp[next]);
			}
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> v >> e;

	adj.resize(v + 1);
	memset(node, -1, sizeof(node));

	int from, to;
	for (int i = 0; i < e; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
	}

	for (int i = 1; i <= v; i++) 
		cin >> money[i];
	
	for (int i = 1; i <= v; i++)
		if (parent[i] == 0) make_scc(i);

	scc_adj.resize(idx);
	res.resize(idx);
	for (int i = 0; i < SCC.size(); i++) {
		for (auto from : SCC[i]) {
			for (auto to : adj[from]) {
				if (node[from] == node[to])
					continue;
				if (scc_adj[node[from]].insert(node[to]).second)
					indeg[node[to]]++;
			}
		}
	}
	int s, p, tmp;
	cin >> s >> p;
	for (int i = 0; i < p; i++) {
		cin >> tmp;
		res[node[tmp]] = true;
	}

	cout << solve(node[s]);
	//code end
	return 0;
}