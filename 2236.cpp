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
int cur;
int ans;

typedef struct _test{
	int x, y, z;

	bool operator<(_test& b) {
		return this->x < b.x;
	}
} test;

vector<int> seg;
int leaf = 1;
test t[500001];

void update(int idx, int x) {
	seg[idx] = x;
	idx /= 2;
	while (idx) {
		seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
		idx /= 2;
	}
}

void solve(int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		cur = min(cur, seg[l]);
		return;
	}

	if (l % 2) {
		cur = min(cur, seg[l]);
		l++;
	}

	if ((r % 2) == 0) {
		cur = min(cur, seg[r]);
		r--;
	}

	solve(l / 2, r / 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		t[tmp].x = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		t[tmp].y = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		t[tmp].z = i;
	}

	sort(t + 1, t + n + 1);

	while (n > leaf)
		leaf <<= 1;

	seg.resize(leaf << 1, INF);

	for (int i = 1; i <= n; i++) {
		cur = INF;
		solve(0, leaf + t[i].y - 1);
		if (cur > t[i].z)
			ans++;
		update(leaf + t[i].y - 1, t[i].z);
	}

	cout << ans;

	//code end
	return 0;
}