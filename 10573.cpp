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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
lint dp[88][10];
lint ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < 88; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		string str;
		cin >> str;
		ans = 0;

		int slen = 1;
		int flag = 0;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] < str[i - 1]) {
				flag = -1;
				break;
			}
			slen++;

		}

		if (flag) {
			cout << flag << '\n';
			continue;
		}

		for (int i = 0; i < slen; i++) {
			if (str[i] == '9') {
				ans += dp[slen - i][1];
			}
			else {
				ans += dp[slen - i][1] - dp[slen - i][str[i] - '0' +1];
			}
		}
		cout << ans << '\n';
	}
	//code end
	return 0;
}