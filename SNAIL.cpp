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
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m;
double dp[1000][2000];

double solve(int days, int climbed) {
	if (days == m)
		return climbed >= n ? 1 : 0;

	double& ret = dp[days][climbed];

	if (ret != -1.0)
		return ret;

	return ret = 0.25 * solve(days + 1, climbed + 1) + 0.75 * solve(days + 1, climbed + 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < 1000; i++) {

			for (int j = 0; j < 2000; j++)
				dp[i][j] = -1.0;
		}
		cout.precision(11);
		cout << solve(0, 0) << '\n';

	}

	//code end
	return 0;
}