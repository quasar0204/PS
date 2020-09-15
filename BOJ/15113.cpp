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
int map[30][30];
bool visit[30][30];
int r, c;
int arr[30];
int ans;
int minel[30];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> r >> c;

	for (int y = 0; y < r; y++) {
		string tmp;
		cin >> tmp;
		for (int x = 0; x < c; x++) {
			if (tmp[x] == 'B') {
				map[y][x] = 1;

			}
			else if (tmp[x] == 'R') {
				map[y][x] = -1;
			}
		}
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (map[y][x] > 0) {
				for (int u = y; u >= 0; u--) {
					for (int l = x; l >= 0; l--) {
						if (map[y][x] * map[u][l] < 0) {
							cout << 0;
							return 0;
						}
						else {
							map[u][l] = map[y][x];
							visit[u][l] = true;
						}
					}
				}
			}
			else if (map[y][x] < 0) {
				for (int u = y; u < r; u++) {
					for (int l = x; l < c; l++) {
						if (map[y][x] * map[u][l] < 0) {
							cout << 0;
							return 0;
						}
						else {
							map[u][l] = map[y][x];
							visit[u][l] = true;
						}
					}
				}
			}
		}
	}
	fill(minel, minel + 30, 1000);

	for (int x = 0; x < c; x++) {
		for (int y = 0; y < r; y++) {
			if (map[y][x] == -1)
				minel[x] = min(y, *min_element(minel, minel + x));
		}
	}
	for (int x = 0; x < c; x++) {
		for (int y = 0; y < r; y++) {
			if (visit[y][x])
				continue;
			if (y >= minel[x])
				break;

			arr[x]++;
		}
		if (arr[x])
			arr[x]++;

		ans += arr[x];
	}

	cout << ans;


	//code end
	return 0;
}