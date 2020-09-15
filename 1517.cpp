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

vector<int> idx;
vector<int> seg;
int leaf = 1;
int arr[500001];
lint ans;

int getIndex(int x) {
	return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
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
		cin >> arr[i];
		idx.push_back(arr[i]);
	}

	sort(all(idx));
	idx.erase(unique(all(idx)), idx.end());

	while (idx.size() > leaf) {
		leaf <<= 1;
	}

	seg.resize(leaf << 1);

	int cur;
	for (int i = n - 1; i >= 0; i--) {
		cur = leaf + getIndex(arr[i]);
		update(cur);
		sum(leaf, cur - 1);
	}
	
	cout << ans;

	//code end
	return 0;
}