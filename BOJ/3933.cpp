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

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
int dp[200];
int ans[5][1 << 15];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	for (int i = 0; i < 200; i++)
		dp[i] = i * i;

	for (int x = 0; 4*dp[x] < (1 <<15); x++) {
		for (int y = x; 3*dp[y] < (1<<15) - dp[x]; y++) {
			for (int z = y; 2*dp[z] < (1 << 15) -dp[x] -dp[y]; z++) {
				for (int w = z; dp[w] < (1 << 15) -dp[x] -dp[y] -dp[z]; w++) {
					cnt = 0;
					if (x == 0)
						cnt++;
					if (y == 0)
						cnt++;
					if (z == 0)
						cnt++;
					if (w == 0)
						cnt++;
					ans[4 - cnt][dp[x] + dp[y] + dp[z] + dp[w]]++;
				}
			}
		}
	}

	while (true) {
		cin >> n;
		if (!n)
			return 0;
		cout << ans[0][n] + ans[1][n] + ans[2][n] + ans[3][n] + ans[4][n] << '\n';
	}
	//code end
	return 0;
}