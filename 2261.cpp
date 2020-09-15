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
pii arr[100000];

lint distance(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool cmpy(pii a, pii b) {
	return a.second < b.second;
}

lint find_min(int l, int r) {
	lint ret = 10LL * INF;
	lint tmp;
	for (int i = l; i < r; i++) {
		for (int j = i + 1; j <= r; j++) {
			tmp = distance(arr[i], arr[j]);
			ret = min(ret, tmp);
		}
	}
	return ret;
}

lint solve(int l, int r) {
	if (r == l)
		return INF * 10LL;
	if (r - l <= 2) {
		return find_min(l, r);
	}

	int m = (l + r) / 2;

	lint left = solve(l, m-1);
	lint right = solve(m + 1, r);
	lint ret = min(left, right);
	lint cur_distance;
	vector<pii> tmp;
	
	for (int i = l; i <= r; i++) {
		cur_distance = arr[i].first - arr[m].first;

		if (cur_distance*cur_distance <= ret) {
			tmp.push_back(arr[i]);
		}
	}

	sort(all(tmp), cmpy);

	for (int i = 0; i < tmp.size() - 1; i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			cur_distance = tmp[i].second - tmp[j].second;

			if (ret <= cur_distance * cur_distance)
				break;
				
			ret = min(ret, distance(tmp[i], tmp[j]));
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