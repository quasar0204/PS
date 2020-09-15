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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m, k;
int leaf = 1;
vector<lint> seg;
lint ans;

void update(int idx, int x) {
	seg[idx] = x;
	idx /= 2;
	while (idx) {
		seg[idx] = seg[idx * 2] * seg[idx * 2 + 1] % MOD;
		idx /= 2;
	}
}

void multiply(int l, int r) {
	if (l > r) 
		return;
	
	if (l == r) {
		ans = (ans*seg[l]) % MOD;
		return;
	}

	if (l % 2) {
		ans = (ans*seg[l]) % MOD;
		l++;
	}
	
	if ((r % 2) == 0) {
		ans = (ans*seg[r]) % MOD;
		r--;
	}

	multiply(l / 2, r / 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m >> k;
	while (n > leaf) {
		leaf <<= 1;
	}
	seg.resize(leaf << 1, 1);

	for (int i = leaf; i < leaf + n; i++) {
		cin >> seg[i];
		int idx = i / 2;
		while (idx) {
			seg[idx] = seg[idx * 2] * seg[idx * 2 + 1] % MOD;
			idx /= 2;
		}
	}
	tc = m + k;
	int a, b, c;
	while (tc--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(leaf + b - 1, c);
		}
		else {
			ans = 1LL;
			multiply(leaf + b - 1, leaf + c - 1);
			cout << ans << '\n';
		}
	}
	//code end
	return 0;
}