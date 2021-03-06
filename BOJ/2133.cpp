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
const int mxn = 10000;

int tc, cnt;
int n;

int dp[31];

int solve(int x) {
	if (x % 2)
		return 0;

	if (x <= 1)
		return 0;

	if (x == 2)
		return 3;

	int& ret = dp[x];

	if (ret != -1)
		return ret;

	ret = 3 * solve(x - 2);
	for (int i = 0; i <= x - 4; i++)
		ret += 2 * solve(i);


	return ret;


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	memset(dp, -1, sizeof(dp));

	cout << solve(n);
	//code end
	return 0;
}
