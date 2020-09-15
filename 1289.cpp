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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
vector<pii> adj[100001];
lint dp[1000001];
bool visit[100001];
lint ans;

lint mod(lint x) {
	if (x < 0)
		return (x + MOD) % MOD;
	else
		return x % MOD;
}

void solve(int root) {
	visit[root] = true;
	lint dir_sum = 0;
	lint via_sum = 0;


	for (pii chd : adj[root]) {
		if (visit[chd.first])
			continue;

		solve(chd.first);
		lint subtree_sum = mod((dp[chd.first] + 1) * chd.second);
		dir_sum = mod(dir_sum + subtree_sum);
		via_sum = mod(via_sum - mod(subtree_sum*subtree_sum));
	}
	dp[root] = dir_sum;
	via_sum = mod(mod(dir_sum*dir_sum) + via_sum);
	if (via_sum % 2) {
		via_sum = mod((via_sum + MOD) / 2);
	}
	else
		via_sum = mod(via_sum / 2);
	ans = mod(ans + dir_sum);
	ans = mod(ans + via_sum);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });
	}

	solve(1);
	cout << ans;

	//code end
	return 0;
}