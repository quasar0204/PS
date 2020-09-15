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
int n, q;
lint x, y, a, b;
lint leaf = 1;
vector<lint> seg;
lint ans;

void update(lint idx, lint c) {
	seg[idx] = c;
	idx /= 2;
	while (idx) {
		seg[idx] = seg[idx * 2 + 1] + seg[idx * 2];
		idx /= 2;
	}
}

void sum(lint l, lint r) {
	if (l > r)
		return;

	if (l == r) {
		ans += seg[l];
		return;
	}

	if (l % 2) {
		ans += seg[l];
		l++;
	}

	if ((r % 2) == 0) {
		ans += seg[r];
		r--;
	}

	sum(l / 2, r / 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> q;
	while (n > leaf) {
		leaf <<= 1;
	}
	seg.resize(leaf * 2 + 1);
	for (lint i = leaf; i < leaf + n; i++) {
		cin >> seg[i];
		lint idx = i / 2;
		while (idx) {
			seg[idx] = seg[idx * 2 + 1] + seg[idx * 2];
			idx /= 2;
		}
	}

	while (q--) {
		cin >> x >> y >> a >> b;
		ans = 0LL;
		sum(leaf + min(x,y) - 1, leaf + max(x,y) - 1);
		cout << ans << '\n';
		update(leaf + a - 1, b);
	}

	//code end
	return 0;
}