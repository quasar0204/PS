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

const int MOD = 1e9 + 3, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int N;
int K;

int dp[1001][1001];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//code start
	cin >> N;
	cin >> K;
	
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int n = 2; n <= N; n++) {
		for (int k = 2; k <= K; k++) {
			dp[n][k] = (dp[n - 1][k] % MOD + dp[n - 2][k - 1] % MOD) % MOD;
		}
	}
	cout << (dp[N-3][K-1] + dp[N-1][K]) % MOD;
//code end
	return 0;
}