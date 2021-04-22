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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
int h, w;
vector<vector<int>> board;
const int cover[4][3][2] = {
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{1,0},{1,1}}
};

bool choose(vector<vector<int>>& b, int type, pii s, int add) {
	bool ret = true;

	for (int i = 0; i < 3; i++) {
		int ny = s.first + cover[type][i][1];
		int nx = s.second + cover[type][i][0];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
			ret = false;
			continue;
		}

		if (board[ny][nx] + add > 1)
			ret = false;

		board[ny][nx] += add;
	}

	return ret;
}

int solve(vector<vector<int>>& b) {
	pii start = { -1,-1 };

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (b[y][x] == 0) {
				start = { y,x };
				break;
			}
		}
		if (start.first != -1)
			break;
	}

	if (start.first == -1) 
		return 1;
	
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (choose(b, i, start, 1))
			ret += solve(b);
		choose(b, i, start, -1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	
	cin >> tc;

	char tmp;
	while (tc--) {
		cin >> h >> w;
		cnt = 0;
		board.clear();
		board.resize(h);
		for (int y = 0; y < h; y++) {
			board[y].resize(w);
			for (int x = 0; x < w; x++) {
				cin >> tmp;
				if (tmp == '.') {
					board[y][x] = 0;
					cnt++;
				}
				else
					board[y][x] = 1;
			}
		}


		if (cnt % 3 != 0) {
			cout << 0 << '\n';
			continue;
		}

		cout << solve(board) << '\n';

	}
	//code end
	return 0;
}