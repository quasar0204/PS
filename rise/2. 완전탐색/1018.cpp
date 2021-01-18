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

int tc;
int n, m;
string str[mxn];

int solve(int Y, int X) {
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;
	char cur = 'B';
	for (int y = Y; y < Y + 8; y++) {
		if (cur == 'B') cur = 'W';
		else cur = 'B';
		for (int x = X; x < X + 8; x++) {
			if (str[y][x] == cur)
				cnt1++;
			else
				cnt2++;

			if (cur == 'B') cur = 'W';
			else cur = 'B';
		}
	}
	return min(cnt1, cnt2);
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> str[i];

	int ans = INF;
	for (int y = 0; y + 7 < n; y++) {
		for (int x = 0; x + 7 < m; x++) {
			ans = min(ans, solve(y, x));
		}
	}

	cout << ans;


	return 0;
}
