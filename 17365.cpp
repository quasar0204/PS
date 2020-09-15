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
int dp[300][301];
map<string, int> mp;
string target;
lint ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	string tmp;
	string pt = "";
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int idx = 0; idx < tmp.length(); idx++) {
			pt += tmp[idx];
			mp[pt]++;
		}
		pt = "";
	}

	cin >> target;

	dp[0][0] = 1;
	for (int i = 0; i < target.length(); i++) {
		tmp = "";
		for (int l = 1; l <= 300; l++) {
			if (i + l - 1 >= target.length())
				break;
			tmp += target[i + l - 1];
			dp[i%300][l] = mp[tmp] % MOD;
			dp[(i+l)%300][0] += dp[i%300][0]*mp[tmp] % MOD;
		}
	}
	cnt = 1;
	
	cout << dp[target.length() % 300][0];

	//code end
	return 0;
}