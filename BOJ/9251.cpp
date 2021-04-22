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

string str1, str2;
int dp[1000][1000];

int solve(int idx1, int idx2) {
	if (idx1 >= str1.length() || idx2 >= str2.length())
		return 0;

	int& ret = dp[idx1][idx2];

	if (ret != -1) return ret;
	
	ret = 0;

	return ret = max((int)(str1[idx1] == str2[idx2]) + solve(idx1 + 1, idx2 + 1),
		max(solve(idx1 + 1, idx2), solve(idx1, idx2 + 1)));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> str1 >> str2;

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0);

	//code end
	return 0;
}