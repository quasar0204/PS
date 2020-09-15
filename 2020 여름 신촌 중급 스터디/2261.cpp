#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 100000;

int tc, cnt;
int n;
pii arr[mxn];

int getSqDis(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int find_min(int l, int r) {
	int ret = INF;
	for (int i = l; i < r; i++) {
		for (int j = i + 1; j <= r; j++) {
			ret = min(ret, getSqDis(arr[i], arr[j]));
		}
	}
	return ret;
}

int solve(int l, int r) {
	if (l == r)
		return INF;
	if (r - l <= 2) {
		return find_min(l, r);
	}

	int m = (l + r) / 2;
	int ret = min(solve(l, m-1), solve(m + 1, r));
	int dist;
	vector<pii> next;

	for (int i = l; i <= r; i++) {
		dist = arr[i].first - arr[m].first;

		if (dist*dist <= ret)
			next.push_back({ arr[i].second, arr[i].first });
	}

	sort(all(next));

	for (int i = 0; i < next.size() - 1; i++) {
		for (int j = i + 1; j < next.size(); j++) {
			dist = next[i].first - next[j].first;

			if (ret <= dist * dist)
				break;

			ret = min(ret, getSqDis(next[i], next[j]));
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + n);

	cout << solve(0, n - 1);
	//code end
	return 0;
}
