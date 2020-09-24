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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 102;

int tc, cnt;
int n;
int p, q;
int arr[mxn];
int dp[mxn][mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";

		cin >> p >> q;
		for (int i = 1; i <= q; i++)
			cin >> arr[i];

		arr[0] = 0;
		arr[q + 1] = p + 1;

		for (int i = 0; i <= q; i++)
			dp[i][i + 1] = 0;

		for (int w = 2; w <= q + 1; w++) {
			for (int i = 0; i + w <= q + 1; i++) {
				int j = i + w, t = INF;
				for (int k = i + 1; k < j; k++) {
					t = min(t, dp[i][k] + dp[k][j]);
				}

				dp[i][j] = t + arr[j] - arr[i] - 2;
			}
		}

		cout << dp[0][q + 1] << '\n';
	}

	//code end
	return 0;
}