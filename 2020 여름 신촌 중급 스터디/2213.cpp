#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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

const int mxn = 10001;
int tc, cnt;
int n;
int cost[mxn];
bool visit[mxn];
int dp[2][mxn];
vector<int> adj[mxn];
vector<int> ans;

int solve(int p, int prePick) {
	visit[p] = true;
	int& pick = dp[1][p];
	int& unpick = dp[0][p];



	if (pick != -1 && prePick == 1)
		return unpick;
	else if (pick != -1 && prePick == 0)
		return max(unpick, pick);

	pick = cost[p];
	unpick = 0;

	for (auto next : adj[p]) {
		if (visit[next] == true)
			continue;

		dp[0][p] += max(solve(next, 1), solve(next, 0));
		dp[1][p] += solve(next, 1);
	}

	if (prePick == 1)
		return unpick;

	return max(unpick, pick);
}

void trace(int p, bool prePick) {
	visit[p] = true;
	bool pick = false;

	if (prePick == false && (dp[1][p] > dp[0][p])) {
		ans.push_back(p);
		pick = true;
	}

	for (auto next : adj[p]) {
		if (visit[next] == true)
			continue;

		trace(next, pick);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[i];

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << '\n';
	//code end
	memset(visit, false, sizeof(visit));
	trace(1, false);

	sort(all(ans));

	for (int x : ans)
		cout << x << ' ';

	return 0;
}