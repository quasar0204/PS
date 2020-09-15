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
int n, s;
int arr[101];
int pSum[101];
int pSqSum[101];
int dp[101][11];

int minError(int from, int to) {
	int m = (int)((double)(pSum[to] - pSum[from - 1]) / (to - from + 1) + 0.5);

	return (pSqSum[to] - pSqSum[from - 1]) - 2 * m * (pSum[to] - pSum[from - 1])
		+ m * m * (to - from + 1);
}

int quantize(int from, int parts) {
	if (from == n + 1) return 0;

	if (parts == 0)
		return INF;

	int& ret = dp[from][parts];

	if (ret != -1)
		return ret;

	ret = INF;
	for (int partSize = 1; from + partSize <= n + 1; partSize++) {
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
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
		cin >> n >> s;
		memset(dp, -1, sizeof(dp));

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		sort(arr + 1, arr + n + 1);

		for (int i = 1; i <= n; i++) {
			pSum[i] = pSum[i - 1] + arr[i];
			pSqSum[i] = pSqSum[i - 1] + arr[i] * arr[i];
		}
		
		cout << quantize(1, s) << '\n';
	}

	//code end
	return 0;
}