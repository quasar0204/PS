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
lint n;
lint k, c;
lint x, y;

lint solve(lint a, lint b) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}

	lint ret = solve(b, a % b);
	lint tmp = y;
	y = x - (a / b)*y;
	x = tmp;

	if (x <= 0) {
		x += b;
		y -= a;
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
		x = 0; y = 0;
		cin >> k >> c;

		if (k == 1) {
			cout << 2 << '\n';
			continue;
		}
		if (c == 1) {
			if (k == 1000000000)
				cout << "IMPOSSIBLE" << '\n';
			else
				cout << k + 1 << '\n';
			continue;
		}

		n = solve(c, k);
		if (n != 1 || x > 1000000000)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << x << '\n';

	}

	//code end
	return 0;
}