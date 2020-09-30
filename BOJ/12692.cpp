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
const int mxn = 15;

int tc, cnt;
int n, m;
int x;
double p;
double dp[2][(1 << mxn) + 1];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	cout << fixed;
	cout.precision(10);

	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";

		cin >> m >> p >> x;

		int n = 1 << m;

		double *prv = dp[0], *nxt = dp[1];
		memset(prv, 0, sizeof(double) * (n + 1));
		prv[n] = 1.0;

		for (int r = 0; r < m; r++) {
			for (int i = 0; i <= n; i++) {
				int jub = min(i, n - i);
				double t = 0.0;
				for (int j = 0; j <= jub; j++) {
					t = max(t, p * prv[i + j] + (1 - p) * prv[i - j]);
				}
				nxt[i] = t;
			}
			swap(prv, nxt);
		}

		int i = (lint)x * n / 1000000;

		cout << prv[i] << '\n';
	}

	//code end
	return 0;
}