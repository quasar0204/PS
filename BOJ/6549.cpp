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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

int tc, cnt;
int n;
lint h[100001];

lint solve(lint left, lint right) {
	if (left > right)
		return 0LL;
	if (left == right)
		return h[left];

	lint mid = (left + right) / 2;

	lint ret = max(solve(left, mid), solve(mid + 1, right));

	lint l = mid;
	lint r = mid + 1;
	lint high = min(h[l], h[r]);
	ret = max(ret, high * (r - l + 1));

	while ((left < l) || (r < right)) {
		if ((l != left) && ((r == right) || (h[l - 1] >= h[r + 1]))) {
			l--;
			high = min(high, h[l]);
			ret = max(ret, high * (r - l + 1));
		}
		else {
			r++;
			high = min(high, h[r]);
			ret = max(ret, high * (r - l + 1));
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	while (true) {
		cin >> n;
		if (n == 0) break;

		for (int i = 1; i <= n; i++)
			cin >> h[i];

		cout << solve(1, n) << '\n';
	}

	//code end
	return 0;
}