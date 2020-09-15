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
const int dr[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
const int dc[] = { 0, -1, 0, 1, 1, -1, -1, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
string board[5];

bool solve(int y, int x, string str, int idx) {
	bool ret = false;

	if (idx > str.length() - 1)
		return ret;

	if (str[idx] != board[y][x])
		return ret;

	if (str.length() - 1 == idx)
		return true;

	for (int i = 0; i < 8; i++) {
		int ny = y + dr[i];
		int nx = x + dc[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
			continue;

		ret = ret | solve(ny, nx, str, idx + 1);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		for (int y = 0; y < 5; y++)
			cin >> board[y];

		cin >> n;

		string tmp;
		for (int i = 0; i < n; i++) {
			bool flag = false;
			cin >> tmp;
			cout << tmp << ' ';
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 5; x++) {
					if (solve(y, x, tmp, 0)) {
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	//code end
	return 0;
}