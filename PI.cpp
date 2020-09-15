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
string str;
int dp[10002];

int level(int a, int b) {
	string s = str.substr(a, b - a + 1);

	if (s == string(s.size(), s[0]))
		return 1;

	bool flag = true;
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i + 1] - s[i] != s[1] - s[0])
			flag = false;
	
	if (flag && abs(s[1] - s[0]) == 1)
		return 2;
	
	bool flag2 = true;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != s[i % 2])
			flag2 = false;

	if (flag2)
		return 4;

	if (flag)
		return 5;

	return 10;
}

int solve(int begin) {
	if (begin == str.size())
		return 0;

	int& ret = dp[begin];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int l = 3; l <= 5; l++) {
		if (begin + l <= str.size()) {
			ret = min(ret, solve(begin + l) + level(begin, begin + l - 1));
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

	cin >> tc;
	while (tc--) {
		cin >> str;

		memset(dp, -1, sizeof(dp));
		cout << solve(0) << '\n';
	}


	//code end
	return 0;
}