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

vector<int> seg;
int leaf = 1;
int ans[100001];

void update(int idx, int x) {
	seg[idx] = x;
	idx /= 2;
	while (idx) {
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
		idx /= 2;
	}
}

int solve(int val, int idx, int l, int r) {
	if (l == r)
		return l;

	int mid = (l + r) / 2;

	if (seg[idx * 2] >= val)
		return solve(val, idx * 2, l, mid);

	return solve(val - seg[idx * 2], idx * 2 + 1, mid + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	while (n > leaf) {
		leaf <<= 1;
	}

	seg.resize(leaf << 1);
	for (int i = leaf; i < leaf + n; i++) {
		update(i, 1);
	}

	int val, idx;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		idx = solve(val + 1, 1, 0, leaf-1);
		ans[idx] = i;
		update(leaf+idx, 0);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}

	//code end
	return 0;
}