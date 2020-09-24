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
const int mxn = 102;

int tc, cnt;
int n, q;
int arr[mxn];
int dp[mxn][mxn];

int solve(int left, int right) {
	if (left + 1 == right) return 0;
	int& ret = dp[left][right];

	if (ret != -1) return ret;

	ret = INF;
	for (int mid = left + 1; mid < right; mid++)
		ret = min(ret, arr[right] - arr[left] - 2 + solve(left, mid) + solve(mid, right));

	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		cin >> n >> q;

		for (int i = 1; i <= q; i++) cin >> arr[i];

		arr[q + 1] = n + 1;
		memset(dp, -1, sizeof(dp));

		cout << solve(0, q + 1) << '\n';
	}

	//code end
	return 0;
}