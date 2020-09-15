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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

const int mxn = 200000;
int tc, cnt;
int n, k;
int a[mxn], b[mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';

		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		

		sort(a, a + n);
		sort(b, b + n);

		int ans = -1;
		for (int i = 0; i < k; i++) {
			ans = max(ans, a[i] + b[(k - 1) - i]);
		}

		cout << ans << '\n';
	}

	return 0;
}