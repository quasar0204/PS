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
int n;

int gcd(int x, int y) {
	if (y)
		return gcd(y, x % y);

	return x;
}

int solve(int n, int m, int x , int y) {
	int _max = (n * m) / gcd(max(n, m), min(n, m));
	int ret = 0;

	ret += x;
	int _y = x % m;

	for (int i = 0; i < m; i++) {
		if (_y == (y % m))
			break;

		_y = (_y + n) % m;

		ret += n;
	}

	if (ret <= _max)
		return ret;

	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	int n, m, x, y;
	while (tc--) {
		cin >> n >> m >> x >> y;
		
		cout << solve(n, m, x, y) << '\n';
	}

	//code end
	return 0;
}