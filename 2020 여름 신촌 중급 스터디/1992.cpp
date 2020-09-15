#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 64;

int tc, cnt;
int n;
string _map[mxn];

void solve(int y, int x, int n) {
	bool flag = true;

	for (int yy = y; yy < y + n; yy++) {
		for (int xx = x; xx < x + n; xx++) {
			if (_map[y][x] != _map[yy][xx]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}

	if (flag)
		cout << _map[y][x];
	else {
		int nn = n / 2;
		cout << '(';
		solve(y, x, nn);
		solve(y, x + nn, nn);
		solve(y + nn, x, nn);
		solve(y + nn, x + nn, nn);
		cout << ')';
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int y = 0; y < n; y++)
		cin >> _map[y];

	solve(0, 0, n);
	//code end
	return 0;
}