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
int n;

int arr[20000];

int solve(int l, int r) {
	if (l == r)
		return arr[l];

	int mid = (l + r) / 2;

	int ret = max(solve(l, mid), solve(mid + 1, r));

	int left = mid;
	int right = mid + 1;
	int cur_w = 2;
	int cur_h = min(arr[left], arr[right]);
	int cur_sq = cur_w * cur_h;

	while (l < left && right < r) {
		if (arr[left - 1] > arr[right + 1]) {
			left--;
			cur_h = min(cur_h, arr[left]);
		}
		else {
			right++;
			cur_h = min(cur_h, arr[right]);
		}
		cur_w++;
		cur_sq = max(cur_sq, cur_h*cur_w);
	}

	while (l < left) {
		left--;
		cur_h = min(cur_h, arr[left]);
		cur_w++;
		cur_sq = max(cur_sq, cur_h*cur_w);
	}
	while (right < r) {
		right++;
		cur_h = min(cur_h, arr[right]);
		cur_w++;
		cur_sq = max(cur_sq, cur_h*cur_w);
	}

	return max(cur_sq, ret);
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
		
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << solve(0, n - 1) << '\n';
	}


	//code end
	return 0;
}