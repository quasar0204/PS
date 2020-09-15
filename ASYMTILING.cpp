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
int n;
int dp[101];

int solve(int w) {

	int& ret = dp[w];

	if (ret != -1)
		return ret;

	if (w <= 1)
		return ret = 1;

	return ret = (solve(w - 1) + solve(w - 2)) % MOD;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	memset(dp, -1, sizeof(dp));

	solve(100);

	while (tc--) {
		cin >> n;
		int ans;
		if (n % 2) 
			ans = (MOD + dp[n] - dp[n / 2]) % MOD;
		else {
			ans = (MOD + dp[n] - dp[n / 2 - 1]) % MOD;
			ans = (MOD + ans - dp[n / 2]) % MOD;
		}


		cout << ans << '\n';
	}
	//code end
	return 0;
}