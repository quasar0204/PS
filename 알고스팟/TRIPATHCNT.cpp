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
int _map[100][100];
int sum[100][100];
int dp[100][100];

int makeSum(int y, int x) {
	int& ret = sum[y][x];

	if (y == n - 1)
		return ret = _map[y][x];

	if (ret != -1)
		return ret;

	return ret = _map[y][x] + max(makeSum(y+1,x), makeSum(y+1,x+1));
}

int _count(int y, int x) {
	if (y == n - 1)
		return 1;

	int& ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;
	if (sum[y + 1][x + 1] >= sum[y + 1][x]) ret += _count(y + 1, x + 1);
	if (sum[y + 1][x + 1] <= sum[y + 1][x]) ret += _count(y + 1, x);

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
		cin >> n;
		memset(sum, -1, sizeof(sum));
		memset(dp, -1, sizeof(dp));

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < y + 1; x++) {
				cin >> _map[y][x];
			}
		}

		makeSum(0, 0);
		cout << _count(0, 0) << '\n';


	}

	//code end
	return 0;
}