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
int n, k;
int w[101], v[101];
int dp[101][101010];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	//dp[1][w[1]] = v[1];
	for (int i = 1; i <= n; i++) {
		dp[i][w[i]] = max(dp[i - 1][w[i]], v[i]);
		for (int j = 0; j <= k; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
			if (dp[i - 1][j]) {
				if (j + w[i] > k)
					continue;
				dp[i][j + w[i]] = max(dp[i - 1][j + w[i]], dp[i - 1][j] + v[i]);
			}
		}
	}

	cout << *max_element(dp[n], dp[n] + k + 1);

	//code end
	return 0;
}