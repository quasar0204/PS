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
char ans[50][50];

int main() {
#ifndef ONLINE_JUDGE
	freopen("Gravity-1001.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> str[i];
	}
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (str[y][x] == '#') {
				ans[y][x] = '#';
				cnt = 0;
				for (int up = y-1; up >= 0; up--) {
					if (str[up][x] == '#') {
						break;
					}
					else if (str[up][x] == 'o') {
						cnt++;
					}
				}
				for (int i = 0; i < cnt; i++) {
					ans[y - 1 - i][x] = 'o';
				}
			}
		}
	}

	for (int y = r-1; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (str[y][x] != '#') {
				cnt = 0;
				for (int up = y; up >= 0; up--) {
					if (str[up][x] == '#') {
						break;
					}
					else if (str[up][x] == 'o') {
						cnt++;
					}
				}
				for (int i = 0; i < cnt; i++) {
					ans[y - i][x] = 'o';
				}
			}
		}
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (ans[y][x] == '\0') {
				cout << '.';
			}
			else {
				cout << ans[y][x];
			}
		}
		cout << '\n';
	}


	//code end
	return 0;
}