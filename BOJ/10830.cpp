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

const int MOD = 1000, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int N;
lint B;

int dp[40][6][6];

int ans[6][6];
int tmp[6][6];

void cross(int idx, int n) {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			for (int k = 1; k <= n; k++) {
				dp[idx][y][x] = (dp[idx][y][x] +dp[idx - 1][y][k] * dp[idx - 1][k][x]) % MOD;
			}
		}
	}
}

void solve(int idx, int n) {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			for (int k = 1; k <= n; k++) {
				tmp[y][x] = (tmp[y][x] + ans[y][k] * dp[idx][k][x]) % MOD;
			}
		}
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			ans[y][x] = tmp[y][x];
			tmp[y][x] = 0;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> N >> B;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> dp[0][y][x];
			dp[y][x][0] %= MOD;
			if (x == y)
				ans[y][x] = 1;
		}
	}
	for (int i = 1; i <= 36; i++) {
		cross(i, N);
	}

	for (int i = 36; i >= 0; i--) {
		if (B >= ((lint)1 << i)) {
			B -= ((lint)1 << i);
			solve(i, N);
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++)
			cout << ans[y][x] << ' ';
		cout << '\n';
	}
	//code end
	return 0;
}