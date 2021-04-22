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

const int MOD = 1000 * 1000 * 1000;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 501;

int tc, cnt;
int n, k;

int dp[mxn][mxn];

int solve(int n, int k) {
	int & ret = dp[n][k];

	if (ret != -1)
		return ret;

	if (k == 0 || k == n)
		return ret = 1;

	if (k == 1 || k == n-1)
		return ret = n;

	return ret = (solve(n - 1, k) + solve(n - 1, k - 1)) % MOD;
}

int H(int n, int k) {
	return solve(n + k - 1, k);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));

	cout << H(k, n);
	//code end
	return 0;
}
