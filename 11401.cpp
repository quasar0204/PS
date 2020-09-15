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

const lint MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

const int mxn = 4000000;
int tc, cnt;
lint N, K;
lint fac[mxn + 1];
lint inv[mxn + 1];

lint power(lint x, lint y) {
	lint ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= MOD;
		}
		x = (x * x) % MOD;
		y /= 2;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> N >> K;

	fac[1] = 1;
	for (int i = 2; i <= mxn; i++) 
		fac[i] = (fac[i - 1] * i) % MOD;
	
	inv[mxn] = power(fac[mxn], MOD - 2);

	for (int i = mxn - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;

	if (N == K || K == 0) {
		cout << 1;
		return 0;
	}

	lint ans = (fac[N] * inv[N - K]) % MOD;
	ans = (ans*inv[K]) % MOD;

	cout << ans;
	

	//code end
	return 0;
}