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

int tc, cnt;
int n;
int dp[100001];
vector<int> arr;

int solve(int x) {
	int& ret = dp[x];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = 0; i < arr.size(); i++) {
		if (x - arr[i] < 1)
			break;

		ret = min(ret, solve(x - arr[i]) + 1);
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i*i <= n; i++) {
		dp[i*i] = 1;
		arr.push_back(i*i);
	}

	cout << solve(n);
	
	//code end
	return 0;
}