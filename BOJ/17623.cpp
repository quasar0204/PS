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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n;

string dp[1001];

string dmap(string tmp) {
	string str = tmp;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '(':
			str[i] = '1';
			break;
		case ')':
			str[i] = '2';
			break;
		case '{':
			str[i] = '3';
			break;
		case '}':
			str[i] = '4';
			break;
		case '[':
			str[i] = '5';
			break;
		case ']':
			str[i] = '6';
			break;
		}
	}

	return str;
}

bool check(string str1, string str2) {
	if (str2 == "")
		return true;

	if (str1.length() < str2.length())
		return true;

	if (str1.length() > str2.length())
		return false;

	return dmap(str1) < dmap(str2);
}

void solve(int n) {
	for (int i = 0; i <= n; i++) {
		dp[i] = "";
	}

	dp[1] = "()";
	dp[2] = "{}";
	dp[3] = "[]";

	for (int i = 4; i <= n; i++) {
		if (i % 5 == 0 && i / 5 != 0) {
			if (check('[' + dp[i / 5] + ']', dp[i]))
				dp[i] = '[' + dp[i / 5] + ']';
		}
		if (i % 3 == 0 && i / 3 != 0) {
			if (check('{' + dp[i / 3] + '}', dp[i]))
				dp[i] = '{' + dp[i / 3] + '}';
		}
		if (i % 2 == 0 && i / 2 != 0) {
			if (check('(' + dp[i / 2] + ')', dp[i]))
				dp[i] = '(' + dp[i / 2] + ')';
		}

		for (int x = 1; x <= i; x++) {
			if (check(dp[i - x] + dp[x], dp[i])) {
				dp[i] = dp[i - x] + dp[x];
			}

			if (check(dp[x] + dp[i - x], dp[i])) {
				dp[i] = dp[x] + dp[i - x];
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	solve(1000);
	while (tc--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	//code end
	return 0;
}