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

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;

int m[501][501], dp[501][501];

int solve(int y, int x) {

	if (dp[y][x])
		return dp[y][x];

	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;

		if (m[y][x] < m[ny][nx]) {
			dp[y][x] = max(dp[y][x], solve(ny, nx) + 1);
		}
	}

	return dp[y][x];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> m[y][x];
		}
	}

	int ans = 1;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			ans = max(ans, solve(y,x));
		}
	}

	cout << ans;
	
	//code end
	return 0;
}