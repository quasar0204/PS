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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 55;

int n;
string str[mxn];

int solve() {
	int ret = 1, cnt = 0;
	char cur = ' ';

	for (int y = 1; y <= n; y++) {
		cur = ' ';
		for (int x = 1; x <= n; x++) {
			if (str[y][x] != cur) {
				ret = max(ret, cnt);
				cnt = 1;
				cur = str[y][x];
			}
			else {
				cnt++;
			}
		}
	}

	for (int x = 1; x <= n; x++) {
		cur = ' ';
		for (int y = 1; y <= n; y++) {
			if (str[y][x] != cur) {
				ret = max(ret, cnt);
				cnt = 1;
				cur = str[y][x];
			}
			else {
				cnt++;
			}
		}
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int y = 1; y <= n; y++) {
		cin >> str[y];
		str[y] = " " + str[y] + " ";
	}

	str[0] = string(' ', n + 2);
	str[n + 1] = string(' ', n + 2);

	int ans = 0;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			ans = max(solve(), ans);
			swap(str[y][x], str[y][x + 1]);
			ans = max(solve(), ans);
			swap(str[y][x], str[y][x + 1]);
			swap(str[y][x], str[y + 1][x]);
			ans = max(solve(), ans);
			swap(str[y][x], str[y + 1][x]);
		}
	}

	cout << ans;


	return 0;
}
