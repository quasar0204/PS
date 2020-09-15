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
int arr[30][30];
int r, c;
string map[30];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}
	for (int x = 0; x < c; x++) {
		for (int y = 0; y < r; y++) {
			if (map[y][x] == 'R') {
				for (int )
			}
		}
	}


	//code end
	return 0;
}