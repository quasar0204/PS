#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dp[555][555];
int in[555][555];

int ans;
int n, m;
const int dr[] = { 0,0,1,-1 };
const int dc[] = { 1,-1,0,0 };

int solve(int y, int x) {
	if (y == 0 && x == 0)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (nx >= n || nx < 0 || ny >= m || ny < 0)
			continue;

		if (in[y][x] < in[ny][nx]) {
			ret += solve(ny, nx);
		}

	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> m >> n;

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			cin >> in[y][x];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(m-1, n-1);

	return 0;

}