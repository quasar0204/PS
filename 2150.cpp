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
int v, e;
int idx;
int parent[10001];
bool finished[10001];
stack<int> st;
vector<vector<int>> SCC;
vector<vector<int>> adj;

int dfs(int x) {
	parent[x] = ++idx;
	st.push(x);

	int p = parent[x];
	for (int y : adj[x]) {
		if (parent[y] == 0) {
			p = min(p, dfs(y));
		}
		else if (!finished[y]) {
			p = min(p, parent[y]);
		}
	}

	if (p == parent[x]) {
		vector<int> scc;
		while (true) {
			int t = st.top();
			st.pop();
			scc.push_back(t);
			finished[t] = true;
			
			if (t == x) {
				sort(all(scc));
				scc.push_back(-1);
				SCC.push_back(scc);
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
	cin >> v >> e;

	adj.resize(v + 1);
	int from, to;
	for (int i = 0; i < e; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
	}

	for (int i = 1; i <= v; i++) {
		if (parent[i] == 0) 
			dfs(i);
	}

	cout << SCC.size() << '\n';
	sort(all(SCC));
	for (int i = 0; i < SCC.size(); i++) {
		for (auto x : SCC[i]) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	//code end
	return 0;
}