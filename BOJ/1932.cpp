#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dp[555][555];
int in[555][555];

int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i ; j++) {
			cin >> in[i][j];
		}
	}

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= y; x++) {
			dp[y][x] = max(dp[y - 1][x - 1] + in[y][x], dp[y - 1][x] + in[y][x]);
		}
	}

	int ans = -1;

	for (int x = 1; x <= n; x++)
		ans = max(dp[n][x], ans);

	cout << ans;

	return 0;
}