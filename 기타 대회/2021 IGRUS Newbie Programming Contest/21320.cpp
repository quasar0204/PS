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

const lint MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 3030;

lint tc, cnt[mxn];
lint n, k;
lint dp[mxn];
lint psum[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	dp[1] = dp[2] = 1;
	psum[1] = 1; psum[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (psum[i - 2] * 2 + 1) % MOD;
		psum[i] = (psum[i - 1] + dp[i]) % MOD;
	}

	for (int i = n - 1; i >= 1; i--)
		cnt[i]++;

	int h = n - 1;
	for (int i = 2; i <= k; i++) {
		cnt[h]--;
		cnt[h - 1] += 2;
		h--;
	}

	lint ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (cnt[i] * dp[i]) % MOD;
		ans %= MOD;
	}

	cout << ans;


	


	return 0;
}
