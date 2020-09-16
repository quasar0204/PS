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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 500;

int tc, cnt;
int n;

int _map[mxn][mxn], dp[mxn][mxn];

int solve(int y, int x) {
	int& ret = dp[y][x];

	if (y == n - 1) return ret = _map[y][x];

	if (ret != -1) return ret;

	return ret = _map[y][x] + max(solve(y + 1, x), solve(y + 1, x + 1));
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			cin >> _map[y][x];
		}
	}
	
	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0);

	//code end
	return 0;
}