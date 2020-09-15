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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,-1,0,1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, X;
double x, y, v;
double v_x, v_y;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n >> X >> v;
	for (int i = 0; i < n; i++) {
		double l, r;
		double tmp;
		cin >> l >> r >> tmp;
		y += ((r - l) / X) * tmp;
	}
	if (abs(y) <= v) {
		v_x = sqrt(v*v - y * y);
	}

	if (2 * v_x < v) {
		cout << "Too hard";
		return 0;
	}

	printf("%.3lf", X / v_x);
	//code end
	return 0;
}