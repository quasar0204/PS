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

const int mxn = 501;
int tc, cnt;
int n;
int dp[mxn][mxn];
int sum[mxn];

int solve(int left, int right) {
	int& ret = dp[left][right];

	if (ret != -1)
		return ret;

	if (left == right)
		return ret = 0;

	ret = INF;

	for (int mid = left; mid < right; mid++) 
		ret = min(ret, 
			solve(left, mid) + solve(mid + 1, right) + sum[right] - sum[left - 1]);
	

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

		for (int i = 1; i <= n; i++) {
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(1, n) << '\n';
	}
	//code end
	return 0;
}