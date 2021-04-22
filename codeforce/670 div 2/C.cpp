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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 100001;

int tc, cnt;
int n;
int chd[mxn];
int visit[mxn];
vector<int> adj[mxn];
int _mxn, _mxnidx;
int diff[mxn];

int dfs(int x) {
	int& ret = chd[x];
	ret = 1;

	for (auto next : adj[x]) {
		if (visit[next]) continue;
		visit[next] = x;
		ret += dfs(next);
	}
	
	if (ret > _mxn)

	return ret;
}

void solve() {
	cin >> n;
	memset(chd, 0, sizeof(chd));
	fill(visit, visit + mxn, 0);
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	_mxn = _mxnidx = 1;


	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visit[1] = -1;
	dfs(1);

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (chd[i] == (chd[1] / 2)) {
			for (auto next : adj[i]) {
				if (next == i || next == visit[i]) continue;

				cout <<  min(i,next) << ' ' << max(i,next) << '\n';
				cout << 1 << ' ' << next << '\n';
				flag = false;
				break;
			}
			break;
		}
	}
	int _min = INF;
	int idx;
	if (flag) {
		for (int i = 2; i <= n; i++) {
			int diff = chd[1] - chd[i] / 2;
			if (_min > diff) {
				idx = i;
				_min = diff;
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
	cin >> tc;
	while (tc--) {
		solve();
	}

	//code end
	return 0;
}