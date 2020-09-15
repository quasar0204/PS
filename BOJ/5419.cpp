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
vector<lint> seg;
int leaf;
lint ans;

pii arr[75000];

bool cmp(pii a, pii b) {
	if (a.first > b.first)
		return true;
	if (a.first == b.first)
		return a.second < b.second;
	return false;
}

int getIndex(int x) {
	return lower_bound(all(IDX),x) - IDX.begin();
}

void update(int idx, int x) {
	seg[idx] = x;
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
	cin >> tc;
	while (tc--) {
		cin >> n;
		seg.resize(0);
		IDX.clear();
		ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			IDX.push_back(arr[i].second);
		}

		sort(all(IDX));
		IDX.erase(unique(all(IDX)), IDX.end());
		
		sort(arr, arr + n, cmp);

		leaf = 1;
		while (IDX.size() > leaf)
			leaf <<= 1;

		seg.resize(leaf << 1);

		int idx;
		for (int i = 0; i < n; i++) {
			idx = leaf + getIndex(arr[i].second);
			sum(leaf, idx);
			update(idx, seg[idx] + 1);
		}

		cout << ans << '\n';
	}
	//code end
	return 0;
}