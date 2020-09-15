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

const int MOD = 1e9 + 7, INF = 987654321*2;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

typedef struct _app{
	int m;
	int c;

	bool operator<(_app& l) {
		return this->c < l.c;
	}

	bool operator<=(_app& l) {
		return this->c <= l.c;
	}
} app;

int tc, cnt;
int n;
int M;
app arr[101];
int dp[10001];
int ans;
int cost;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> M;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].c;
		cost += arr[i].c;
	}
	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = cost; j >= arr[i].c; j--) {
			dp[j] = max(dp[j], dp[j - arr[i].c] + arr[i].m);
		}
	}

	cout << (lower_bound(dp, dp + cost + 1, M) - dp);
	//code end
	return 0;
}