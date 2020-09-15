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
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m;

vector<lint> seg;
int leaf = 1;
lint ans;

void update(int idx, int val) {
	idx += leaf - 1;
	seg[idx] = val;
	idx /= 2;
	while (idx) {
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
		idx /= 2;
	}
}

void sum(int l, int r) {
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

	if (r % 2 == 0) {
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
	cin >> n >> m;

	for (leaf = 1; n > leaf; leaf <<= 1);

	seg.resize(leaf << 1);

	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a) {
			update(b, c);
		}
		else {
			ans = 0LL;
			sum(min(b,c)+leaf-1, max(c,b)+leaf-1);
			cout << ans << '\n';
		}
	}

	//code end
	return 0;
}