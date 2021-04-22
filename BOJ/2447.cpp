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
const int mxn = 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3;

int tc, cnt;
int N;
char _map[mxn][mxn];

void solve(int y, int x, int n) {
	if (n == 1) {
		_map[y][x] = '*';
		return;
	}

	int nn = n / 3;
	solve(y, x, nn);
	solve(y, x + nn, nn);
	solve(y, x + 2 * nn , nn);
	solve(y + nn, x, nn);
	//solve(y + nn, x + nn, nn);
	solve(y + nn, x + 2 * nn, nn);
	solve(y + 2 * nn, x, nn);
	solve(y + 2 * nn, x + nn, nn);
	solve(y + 2 * nn, x + 2 * nn, nn);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> N;

	solve(0, 0, N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (_map[y][x] == '*')
				cout << _map[y][x];
			else
				cout << ' ';
		}
		cout << '\n';
	}

	//code end
	return 0;
}