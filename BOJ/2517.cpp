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
vector<int> IDX;
vector<int> seg;
int leaf = 1;
int ans;
int in[500001];

int getInverseIndex(int x) {
	return IDX.end() - lower_bound(all(IDX), x) - 1;
}

void update(int idx) {
	seg[idx]++;
	idx /= 2;
	while (idx) {
		seg[idx]++;
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
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in[i];
		IDX.push_back(in[i]);
	}

	sort(all(IDX));
	IDX.erase(unique(all(IDX)), IDX.end());

	while (IDX.size() > leaf) {
		leaf <<= 1;
	}

	seg.resize(leaf << 1);

	int idx, val;
	for (int i = 0; i < n; i++) {
		val = in[i];
		idx = getInverseIndex(val);
		update(leaf + idx);
		ans = 0;
		sum(leaf, leaf + idx);
		cout << ans << '\n';
	}
	//code end
	return 0;
}