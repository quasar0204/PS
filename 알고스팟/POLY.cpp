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

const int MOD = 10*1000*1000, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
int dp[101][101];

int solve(int n, int first) {
	if (n == first)
		return 1;

	int& ret = dp[n][first];

	if (ret != -1)
		return ret;

	ret = 0;
	for (int second = 1; second <= n - first; second++) {
		int add = second + first - 1;
		add *= solve(n - first, second);
		add %= MOD;
		ret = (ret + add) % MOD;
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
		memset(dp, -1, sizeof(dp));
		

		cout << solve(n,0) << '\n';
	}

	//code end
	return 0;
}