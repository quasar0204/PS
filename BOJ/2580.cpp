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
const int dr[] = { 0,0,0,1,1,1,2,2,2 };
const int dc[] = { 0,1,2,0,1,2,0,1,2 };
const double PI = 3.14159265359;

int tc;
int n, cnt;
int _map[9][9];
bool row[9][10], col[9][10], squ[9][10];
int _m[81];
bool flag;

int s(int y, int x) {
	return 3 * (y / 3) + x / 3;
}

void solve(int idx) {
	if (idx == n) {
		if (!flag) {
			for (int y = 0; y < 9; y++) {
				for (int x = 0; x < 9; x++) {
					cout << _map[y][x] << ' ';
				}
				cout << '\n';
			}
			flag = true;
		}
		return;
	}

	int x = _m[idx] % 9, y = _m[idx] / 9;

	for (int i = 1; i <= 9; i++) {
		if (row[y][i] || col[x][i] || squ[s(y, x)][i])
			continue;

		row[y][i] = col[x][i] = squ[s(y, x)][i] = true;
		_map[y][x] = i;
		solve(idx + 1);
		_map[y][x] = 0;
		row[y][i] = col[x][i] = squ[s(y, x)][i] = false;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> _map[y][x];
			if (_map[y][x]) {
				row[y][_map[y][x]] = true;
				col[x][_map[y][x]] = true;
				squ[s(y, x)][_map[y][x]] = true;
			}
			else {
				_m[n++] = y * 9 + x;
			}
		}
	}

	solve(0);
	
	//code end
	return 0;
}