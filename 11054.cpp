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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
int arr[1002];
int dp[1002][2];
int ans[1002];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n+1; j > i; j--) {
			if (arr[j] < arr[i])
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ans[i] = dp[i][0] + dp[i][1] - 1;

	}

	cout << *max_element(ans, ans + n + 1);
	//code end
	return 0;
}