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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n;
int dp[1001][1001];
int in[1001];

int solve(int l, int r, int flag) {
	if (l > r)
		return 0;

	if (dp[l][r])
		return dp[l][r];

	if (flag) {
		if (l == r)
			return dp[l][r] = in[l];

		dp[l][r] = max(solve(l + 1, r, 1 - flag) + in[l], solve(l, r - 1, 1 - flag) + in[r]);
		return dp[l][r];
	}
	else {
		if (l == r)
			return dp[l][r] = 0;

		dp[l][r] = min(solve(l + 1, r, 1 - flag), solve(l, r - 1, 1 - flag));
		return dp[l][r];
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
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> in[i];

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = dp[i][j] = 0;

		cout << solve(1, n, 1) << '\n';

	}
	//code end
	return 0;
}