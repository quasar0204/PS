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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
pair<lint,lint> arr[501];
lint dp[501][501];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;

	}
	
	for (int i = n; i >= 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = INF;
			for (int k = i; k <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i].first * arr[k].second * arr[j].second);
			}
		}
	}
	cout << dp[1][n];
	//code end
	return 0;
}