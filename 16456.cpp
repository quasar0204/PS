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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 9, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n;
int dp[50002][3];

int main() {

	cin >> n;
	dp[1][1] = 1;
	dp[2][1] = 1;

	for (int i = 3; i <= n + 1; i++) {
		dp[i][1] = (dp[i - 1][1] % MOD + dp[i - 1][2] % MOD) % MOD;
		dp[i][2] = dp[i - 2][1] % MOD;
	}

	cout << (dp[n][1] + dp[n][2]) % MOD << '\n';

	//code end
	return 0;
}