#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[1*1000*1000 + 1];
int cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i - a > 0)
			dp[i] = min(dp[i], dp[i - a - 1] + 1);
		if (i - b > 0)
			dp[i] = min(dp[i], dp[i - b - 1] + 1);
	}

	cout << dp[n];

	return 0;

}