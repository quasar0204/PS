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
int n, s;
lint dp[101][101][2]; // dp[left][right][move]
lint sum[101];

lint solve(int left, int right, int move) {
	if (left == 1 && right == n)
		return 0;

	lint& ret = dp[left][right][move];

	if (ret != -1)
		return ret;

	ret = LINF;
	lint now = (move == 1) ? right : left;
	lint remain = n - (right - left + 1);
	if (left > 1) {
		ret = min(ret, solve(left - 1, right, 0) + remain * (sum[now] - sum[left - 1]));
	}
	if (right < n) {
		ret = min(ret, solve(left, right + 1, 1) + remain * (sum[right + 1] - sum[now]));
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
		cin >> n;
		cin >> s;

		for (int i = 2; i <= n; i++) {
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(s, s, 0) << '\n';
	}

	//code end
	return 0;
}