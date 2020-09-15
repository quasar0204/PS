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
int arr[201];
int k;
int dp[201][201];

int solve(int l, int r) {
	if (l == r) 
		return 0;

	if (dp[l][r] >= 0)
		return dp[l][r];

	dp[l][r] = INF;
	for (int i = l + 1; i <= r; i++) {
		int same = (arr[l] != arr[i]) ? 1 : 0;
		dp[l][r] = min(dp[l][r], solve(l, i-1) + solve(i, r) + same);
	}
	return dp[l][r];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	cout << solve(1, n);
	//code end
	return 0;
}