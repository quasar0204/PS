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

const int MOD = 1e9 + 7, INF = 1987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m;
int leaf = 1;

vector<pii> seg;
pii ans;

void solve(int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		ans.first = min(ans.first, seg[l].first);
		ans.second = max(ans.second, seg[l].second);
		return;
	}

	if (l % 2) {
		ans.first = min(ans.first, seg[l].first);
		ans.second = max(ans.second, seg[l].second);
		l++;
	}

	if ((r % 2) == 0) {
		ans.first = min(ans.first, seg[r].first);
		ans.second = max(ans.second, seg[r].second);
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
	cin >> n >> m;
	while (n > leaf) {
		leaf <<= 1;
	}
	seg.resize(leaf << 1, { INF,0 });

	for (int i = leaf; i < leaf + n; i++) {
		int idx = i;
		cin >> seg[idx].first;
		seg[idx].second = seg[idx].first;
		idx /= 2;
		while (idx) {
			seg[idx].first = min(seg[2*idx].first, seg[2*idx + 1].first);
			seg[idx].second = max(seg[2*idx].second, seg[2*idx + 1].second);
			idx /= 2;
		}
	}
	int a, b;
	while (m--) {
		cin >> a >> b;

		ans = { INF, 0 };
		solve(leaf + a - 1, leaf + b - 1);
		cout << ans.first << ' ' << ans.second << '\n';
	}
	//code end
	return 0;
}