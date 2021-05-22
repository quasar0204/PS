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
const int mxn = 16;

int tc, cnt;
int n;
int t[mxn], s[mxn];
int dp[mxn][1 << mxn];

int solve(int here, int visit, int cnt) {
	int &ret = dp[here][visit];
	if (ret != -1) return ret;
	if (cnt == n) return ret = 0;

	for (int i = 0; i < here; i++)
		if (!(visit & (1 << i)) && (t[here] % t[i] == 0)) return ret;

	ret = (cnt + 1) * s[here];
	visit = visit | (1 << here);
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i)) continue;
		m = max(m, solve(i, visit, cnt + 1));
	}

	return ret = ret + m;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> t[i] >> s[i];
	
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i, 0, 0));

	cout << ans;

	return 0;
}
