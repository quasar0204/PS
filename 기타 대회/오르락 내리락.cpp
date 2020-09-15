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
int n1, n2;
const int mxn = 1000000;
int dp[mxn + 1];
lint sum[mxn + 1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	fill(dp, dp + mxn + 1, INF);
	
	dp[2] = 1;
	for (int i = 2; i <= mxn; i++) {
		if (i % 2)
			dp[i] = min(dp[i], dp[i + 1] + 1);
		if (i * 2 <= mxn) {
			dp[i * 2] = min(dp[i] + 1, dp[2*i]);
		}
	}
	sum[1] = 0;
	for (int i = 2; i <= mxn; i++) {
		sum[i] = sum[i - 1] + dp[i];
	}
	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';

		cin >> n1 >> n2;

		cout << sum[n2] - sum[n1-1] << '\n';
	}

	//code end
	return 0;
}