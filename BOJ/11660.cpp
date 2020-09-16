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
const int mxn = 1024 + 1;

int tc, cnt;
int n, m;
lint sum[mxn][mxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> sum[y][x];
			sum[y][x] = sum[y][x] + sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1];
		}
	}

	while (m--) {
		int x1, x2, y1, y2;

		cin >> y1 >> x1 >> y2 >> x2;

		cout << sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1] << '\n';
	}

	//code end
	return 0;
}