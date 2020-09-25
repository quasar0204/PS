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
const int mxn = 5000;

int tc, cnt;
int n;
int arr[mxn];
int s[mxn];
int solve(int k) {
	int ret = 0;
	int sum = 0;
	memset(s, 0, sizeof(s));

	for (int i = 0; i <= n - k; i++) {
		if (i - k >= 0) sum -= s[i - k];

		if ((arr[i] + sum) % 2) {
			ret++;
			s[i] = 1;
			sum++;
		}
	}

	for (int i = n - k + 1; i < n; i++) {
		sum -= s[i - k];

		if ((arr[i] + sum) % 2) {
			ret = INF;
			break;
		}
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'B') {
			arr[i] = 1;
			cnt++;
		}
	}


	int K = 1, M = cnt;
	for (int k = 2; k <= n; k++) {
		int m = solve(k);
		if (M > m) {
			M = m;
			K = k;
		}
	}

	cout << K << ' ' << M;

	//code end
	return 0;
}