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

const int mxn = 3 * 3 * 3 * 3 * 3 * 3 * 3;
int tc, cnt;
int n;
int ans[3];
int _map[mxn][mxn];

void solve(int Y, int X, int N) {
	if (N == 1) {
		ans[_map[Y][X] + 1]++;
		return;
	}

	bool flag = false;
	
	for (int y = Y; y < Y + N; y++) {
		for (int x = X; x < X + N; x++) {
			if (_map[Y][X] != _map[y][x]) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (!flag) {
		ans[_map[Y][X] + 1]++;
	}
	else {
		int nn = N / 3;
		solve(Y, X, nn);
		solve(Y + nn, X, nn);
		solve(Y + 2*nn, X, nn);
		solve(Y, X + nn, nn);
		solve(Y + nn, X + nn, nn);
		solve(Y + 2 * nn, X + nn, nn);
		solve(Y, X + 2*nn, nn);
		solve(Y + nn, X + 2 * nn, nn);
		solve(Y + 2 * nn, X + 2 * nn, nn);
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
		for (int x = 0; x < n; x++)
			cin >> _map[y][x];

	solve(0, 0, n);
	
	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
	//code end
	return 0;
}