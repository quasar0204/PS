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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int r, c;
string str[50];
int visit[50][50];

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int dy = y + dr[i];
		int dx = x + dc[i];

		if (dx < 0 || dx >= c)
			continue;

		if (dy < 0 || dy >= r)
			continue;
		
		if (str[dy][dx] == 'W')
			continue;
	
		if (visit[dy][dx])
			continue;

		visit[dy][dx] = true;
		dfs(dy, dx);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Islands-1001.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> str[i];

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (str[y][x] == 'L' && !visit[y][x]) {
				cnt++;
				dfs(y, x);
			}
		}
	}

	cout << cnt;
	
	//code end
	return 0;
}