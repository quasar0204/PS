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
const int mxn = 22;

int tc, cnt;
int n;
vector<int> adj[mxn];
int deg[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b;
	for (int i = 0; i < 12; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++; deg[b]++;
	}

	for (int i = 1; i <= 12; i++) {
		int cur = 0;
		for (auto x : adj[i])
			cur += deg[x];
		if (adj[i].size() == 3 && cur == 6) cout << i;
	}


	return 0;
}
