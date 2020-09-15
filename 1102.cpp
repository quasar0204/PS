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
int m[16][16];
int dp[16][1 << 16];
int p;
int on;
int ans;
//vector<int> on;

int solve(int ct, int on) {
	if (ct >= p)
		return 0;

	int &ret = dp[ct][on];

	if (ret >= 0)
		return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (on & 1 << i) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;

				if (on & (1 << j))
					continue;

				ret = min(ret, solve(ct + 1, on | 1 << j) + m[i][j]);
			}
		}
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
			cin >> m[y][x];
	string str;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'Y') {
			on = on | 1 << i;
			cnt++;
		}
	}
	cin >> p;
	memset(dp, -1, sizeof(dp));

	ans = solve(cnt, on);
	if (ans == INF) ans = -1;
	cout << ans;
	//code end
	return 0;
}