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

const int maxSize = 100001;

int tc, cnt;
int n;
int v, e;
int idx;
int sccInx;
vector<vector<int>> adj;
vector<vector<int>> SCC;
stack<int> st;
int parent[maxSize];
int finish[maxSize];
int indeg[maxSize];
int SCCIndeg[maxSize];
int scc_idx;

void init() {
	idx = 0;
	scc_idx = 0;
	sccInx = 0;
	cnt = 0;
	adj.clear();
	SCC.clear();
	memset(parent, 0, sizeof(parent));
	memset(finish, 0, sizeof(finish));
	memset(indeg, 0, sizeof(indeg));
	memset(SCCIndeg, 0, sizeof(SCCIndeg));
}

int dfs(int x) {
	parent[x] = ++idx;
	st.push(x);

	int ret = parent[x];
	for (int y : adj[x]) {
		if (parent[y] == 0)
			ret = min(ret, dfs(y));
		else if (!finish[y])
			ret = min(ret, parent[y]);
	}

	if (ret == parent[x]) {
		vector<int> scc;
		++scc_idx;
		while (true) {
			int t = st.top();
			st.pop();

			scc.push_back(t);
			finish[t] = scc_idx;

			if (t == x) {
				SCC.push_back(scc);
				break;
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
	cin >> tc;
	while (tc--) {
		init();

		cin >> v >> e;

		adj.resize(v + 1);
		int from, to;
		for (int i = 0; i < e; i++) {
			cin >> from >> to;
			adj[from].push_back(to);
			indeg[to]++;
		}

		for (int i = 1; i <= v; i++) {
			if (parent[i] == 0)
				dfs(i);
		}


		for (int i = 0; i < SCC.size(); i++) {
			for (auto from : SCC[i]) {
				for (auto to : adj[from]) {
					if (finish[from] == finish[to])
						continue;
					SCCIndeg[finish[to]]++;
				}
			}
		}
		for (int i = 1; i <= scc_idx; i++) {
			if (SCCIndeg[i] == 0)
				cnt++;
		}
		cout << cnt << '\n';

	}

	//code end
	return 0;
}