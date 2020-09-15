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
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 0, 1 };
const int dc[] = { 0, -1, 1, 0 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m;
int rx, ry, bx, by;
string str[10];

bool move(int& x, int& y, int type, char ball) {
	str[y][x] = '.';
	while (str[y + dr[type]][x + dc[type]] == '.' || str[y + dr[type]][x + dc[type]] == 'O') {
		if (str[y + dr[type]][x + dc[type]] == 'O')
			return true;

		x = x + dc[type];
		y = y + dr[type];
	}

	str[y][x] = ball;

	return false;
}

int search(int& rx, int& ry, int& bx, int& by, int type, int time) {
	int ret = -1;

	if (time + 1 > 10)
		return INF;

	bool flag = true;
	if (dc[type] * bx + dr[type] * by > dc[type] * rx + dr[type] * ry) {
		move(bx, by, type, 'B');
		move(rx, ry, type, 'R');
	}
	else {
		flag = false;
		if (move(rx, ry, type, 'R'))
			ret = time + 1;
		move(bx, by, type, 'B');
	}

	if (ret != -1) {
		if (flag) {
			move(rx, ry, 3 - type, 'R');
			move(bx, by, 3 - type, 'B');
		}
		else {
			move(bx, by, 3 - type, 'B');
			move(rx, ry, 3 - type, 'R');

		}
		return ret;
	}

	ret = INF;
	for (int i = 0; i < 4; i++) {
		if ((i == type) || (i == (3-type)))
			continue;
		ret = min(ret, search(rx, ry, bx, by, i, time + 1));
	}

	if (flag) {
		move(rx, ry, 3 - type, 'R');
		move(bx, by, 3 - type, 'B');
	}
	else {
		move(bx, by, 3 - type, 'B');
		move(rx, ry, 3 - type, 'R');

	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'R') {
				ry = i; rx = j;
			}
			if (str[i][j] == 'B') {
				by = i; bx = j;
			}
		}
	}

	int ans = INF;

	for (int i = 0; i < 4; i++) {
		ans = min(ans, search(rx, ry, bx, by, i, 0));
	}

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	//code end
	return 0;
}