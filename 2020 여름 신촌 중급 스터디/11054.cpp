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

int tc, cnt;
int n;

vector<int> l, r;
int arr[1000];
int dp[1000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		cin >> arr[i];

		if (l.empty() || l.back() < arr[i]) {
			l.push_back(arr[i]);
			dp[n - 1 - i] = l.size();
		}
		else {
			int idx = lower_bound(all(l), arr[i]) - l.begin();
			l[idx] = arr[i];
			dp[n - 1 - i] = idx + 1;
		}
	}

	int _max = 1;
	for (int i = 0; i < n; i++) {
		if (r.empty() || r.back() < arr[i]) {
			r.push_back(arr[i]);
			dp[n - 1 - i] += r.size();
		}
		else {
			int idx = lower_bound(all(r), arr[i]) - r.begin();
			r[idx] = arr[i];
			dp[n - 1 - i] += idx + 1;
		}
		_max = max(_max, dp[n - 1 - i] - 1);
	}

	cout << _max;
	//code end
	return 0;
}