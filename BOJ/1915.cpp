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
const int mxn = 1000;

int tc, cnt;
int n, m;

string _map[mxn];
int dp[mxn][mxn];
int ans;

int solve(int y, int x) {
	int& ret = dp[y][x];
	if (y == n - 1 || x == m - 1) {
		ret = (int)(_map[y][x] - '0');
		ans = max(ans, ret);
		return ret;
	}

	if (ret != -1) return ret;

	if (_map[y][x] == '1') {
		ret = 1 + min(solve(y + 1, x + 1), min(solve(y, x + 1), solve(y + 1, x)));
	}
	else
		ret = 0;

	ans = max(ans, ret);

	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> _map[i];

	memset(dp, -1, sizeof(dp));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (dp[y][x] == -1) solve(y, x);
		}
	}

	cout << ans * ans;

	//code end
	return 0;
}