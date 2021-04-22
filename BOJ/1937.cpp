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
int n;

int _map[500][500];
int dp[500][500];

int solve(int y, int x) {
	int& ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny >= n || ny < 0 || nx >= n || nx < 0)
			continue;

		if (_map[y][x] >= _map[ny][nx])
			continue;

		ret = max(ret, solve(ny, nx) + 1);
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> _map[y][x];

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			ans = max(ans, solve(y, x));
		}
	}

	cout << ans;
	//code end
	return 0;
}