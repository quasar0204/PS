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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n, m;
int leaf = 1;
int seg[4444][4444];
int ans;

void update(int idx_x, int idx_y, int c) {
	seg[idx_y][idx_x] = c;
	while (idx_x / 2) {
		int idx = idx_y / 2;
		while (idx) {
			seg[idx][idx_x] = seg[idx * 2][idx_x] + seg[idx * 2 + 1][idx_x];
			idx /= 2;
		}

		idx_x /= 2;
		seg[idx_y][idx_x] = seg[idx_y][idx_x * 2] + seg[idx_y][idx_x * 2 + 1];
	}

	idx_y /= 2;
	while (idx_y) {
		seg[idx_y][1] = seg[idx_y * 2][1] + seg[idx_y * 2 + 1][1];
		idx_y /= 2;
	}
}



void sum(int l_x, int r_x, int l_y, int r_y) {
	if (l_x > r_x)
		return;

	if (l_y > r_y)
		return;

	if (l_x == r_x && l_y == r_y) {
		ans += seg[l_y][l_x];
		return;
	}

	if (l_x == r_x) {
		if (l_y % 2) {
			ans += seg[l_y][l_x];
			l_y++;
		}
		if ((r_y % 2) == 0) {
			ans += seg[r_y][l_x];
			r_y--;
		}
		sum(l_x, r_x, l_y / 2, r_y / 2);
		return;
	}

	if (l_y == r_y) {
		if (l_x % 2) {
			ans += seg[l_y][l_x];
			l_x++;
		}
		if ((r_x % 2) == 0) {
			ans += seg[l_y][r_x];
			r_x--;
		}
		sum(l_x / 2, r_x / 2, l_y, r_y);
		return;
	}
	int LX = l_x, RX = r_x, LY = l_y, RY = r_y;
	if (LY % 2) {
		sum(l_x, r_x, LY, LY);
		l_y++;
	}
	if ((RY % 2) == 0) {
		sum(l_x, r_x, RY, RY);
		r_y--;
	}
	sum(l_x, r_x, l_y / 2, r_y / 2);

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;
	while (n > leaf)
		leaf <<= 1;

	int idx;
	for (int y = leaf; y < leaf + n; y++) {
		for (int x = leaf; x < leaf + n; x++) {
			cin >> seg[y][x];
			update(x, y, seg[y][x]);
		}
	}

	for (int x = 1; x < (leaf << 1); x++) {
		for (int y = leaf; y < leaf + n; y++) {
			idx = y / 2;
			while (idx) {
				seg[idx][x] = seg[idx * 2][x] + seg[idx * 2 + 1][x];
				idx /= 2;
			}
		}
	}

	int w, x1, y1, x2, y2, c;
	while (m--) {
		cin >> w;
		if (w == 1) {
			ans = 0;
			cin >> x1 >> y1 >> x2 >> y2;
			sum(y1 + leaf - 1, y2 + leaf - 1, x1 + leaf - 1, x2 + leaf - 1);
			cout << ans << '\n';
		}
		else {
			cin >> x1 >> y1 >> c;
			update(y1 + leaf - 1, x1 + leaf - 1, c);
		}
	}


	return 0;
}