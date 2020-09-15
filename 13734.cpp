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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 }; //À§, ¿Þ, ¾Æ, ¿À
const double PI = 3.14159265359;

int tc, cnt;
int n;
int r, c;
string str[50];
string order;
pii start, goal;
pii cur;
int num[4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> str[i];
	cin >> order;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (str[y][x] == 'S') {
				start = { x, y };
			}
			else if (str[y][x] == 'G') {
				goal = { x,y };
			}

		}
	}

	cur = { start.first, start.second };

	for (char c : order) {
		int idx;
		if (c == 'U') {
			idx = 0;
			num[idx]++;
		}
		else if (c == 'L') {
			idx = 1;
			num[idx]++;
		}
		else if (c == 'D') {
			idx = 2;
			num[idx]++;
		}
		else if (c == 'R') {
			idx = 3;
			num[idx]++;
		}

		int ny = cur.second + dr[idx];
		int nx = cur.first + dc[idx];

		if (ny < 0 || ny >= r)
			continue;
		if (nx < 0 || nx >= c)
			continue;

		if (str[ny][nx] == '#')
			continue;

		cur = { nx, ny };
	}

	int remain_x = goal.first - cur.first;
	int remain_y = goal.second - cur.second;

	if (remain_y > 0) {
		while (remain_y >= 2) {
			if (num[2]) {
				num[2]--;
				remain_y -= 2;
				cnt++;
			}
			else {
				remain_y -= 1;
				cnt++;
			}
		}
		if (remain_y == 1)
			cnt++;
	}

	if (remain_y < 0) {
		while (remain_y <= -2) {
			if (num[0]) {
				num[0]--;
				remain_y += 2;
				cnt++;
			}
			else {
				remain_y += 1;
				cnt++;
			}
		}
		if (remain_y == -1)
			cnt++;
	}

	if (remain_x > 0) {
		while (remain_x >= 2) {
			if (num[1]) {
				num[1]--;
				remain_x -= 2;
				cnt++;
			}
			else {
				remain_x -= 1;
				cnt++;
			}
		}
		if (remain_x == 1)
			cnt++;
	}

	if (remain_x < 0) {
		while (remain_x <= -2) {
			if (num[3]) {
				num[3]--;
				remain_x += 2;
				cnt++;
			}
			else {
				remain_x += 1;
				cnt++;
			}
		}
		if (remain_x == -1)
			cnt++;
	}

	cout << cnt;
	//code end
	return 0;
}