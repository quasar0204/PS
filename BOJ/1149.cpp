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
int dp[3][1001];
int cost[3][1001];

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int cur = 0; cur < 3; cur++) {
			dp[cur][i] = INF;
			for (int pre = 0; pre < 3; pre++) {
				if (cur == pre)
					continue;

				dp[cur][i] = min(dp[cur][i], dp[pre][i - 1] + cost[cur][i]);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[0][i] >> cost[1][i] >> cost[2][i];


	solve();

	cout << min(dp[2][n], min(dp[0][n], dp[1][n]));
	//code end
	return 0;
}