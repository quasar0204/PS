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
int arr[100000];

lint solve(int l, int r) {
	if (r == l) {
		return 1LL* arr[l] * arr[l];
	}

	int m = (l + r) / 2;

	lint left = solve(l, m);
	lint right = solve(m+1, r);

	lint cur_sum = arr[m] + arr[m+1];
	int cur_min = min(arr[m], arr[m + 1]);
	lint mid = cur_sum * cur_min;

	int idx_l = m;
	int idx_r = m + 1;

	while (l < idx_l && idx_r < r) {
		if (arr[idx_l - 1] < arr[idx_r + 1]) {
			idx_r++;
			cur_min = min(cur_min, arr[idx_r]);
			cur_sum += arr[idx_r];
		}
		else {
			idx_l--;
			cur_min = min(cur_min, arr[idx_l]);
			cur_sum += arr[idx_l];
		}
		mid = max(mid, cur_sum*cur_min);
	}
	while (l < idx_l) {
		idx_l--;
		cur_min = min(cur_min, arr[idx_l]);
		cur_sum += arr[idx_l];
		mid = max(mid, cur_sum*cur_min);
	}
	while (idx_r < r) {
		idx_r++;
		cur_min = min(cur_min, arr[idx_r]);
		cur_sum += arr[idx_r];
		mid = max(mid, cur_sum*cur_min);
	}
	return max(mid, max(left, right));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << solve(0, n - 1);

	//code end
	return 0;
}