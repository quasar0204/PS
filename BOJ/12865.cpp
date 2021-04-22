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

int tc, cnt;
int n, k;
pii arr[100];
int dp[100][100001];
int solve(int start, int remain) {
	if (start == n)
		return 0;

	int& ret = dp[start][remain];

	if (ret != -1) return ret;

	ret = 0;

	ret = max(ret, solve(start + 1, remain));

	if (remain - arr[start].first >= 0)
		ret = max(ret, solve(start + 1, remain - arr[start].first) + arr[start].second);

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	memset(dp, -1, sizeof(dp));

	cout << solve(0, k);

	//code end
	return 0;
}