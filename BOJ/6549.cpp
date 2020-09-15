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
lint arr[100000];

lint solve(int l, int r) {
	if (l == r) {
		return arr[l];
	}

	int m = (l + r) / 2;
	
	lint left = solve(l, m);
	lint right = solve(m + 1, r);

	lint cur_h = min(arr[m], arr[m + 1]);
	lint cur_w = 2;
	lint cur_sq = cur_h * cur_w;
	int idx_l = m;
	int idx_r = m + 1;

	while (l < idx_l && idx_r < r) {
		if (arr[idx_l - 1] > arr[idx_r + 1]) {
			idx_l--;
			cur_h = min(cur_h, arr[idx_l]);
		}
		else {
			idx_r++;
			cur_h = min(cur_h, arr[idx_r]);
		}
		cur_w++;
		cur_sq = max(cur_sq, cur_h*cur_w);
	}

	while (l < idx_l) {
		idx_l--;
		cur_h = min(cur_h, arr[idx_l]);
		cur_w++;
		cur_sq = max(cur_sq, cur_h*cur_w);
	}

	while (idx_r < r) {
		idx_r++;
		cur_h = min(cur_h, arr[idx_r]);
		cur_w++;
		cur_sq = max(cur_sq, cur_h*cur_w);
	}

	return max(cur_sq, max(left, right));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) 
			cin >> arr[i];
		
		cout << solve(0, n-1) << '\n';

	}
	//code end
	return 0;
}