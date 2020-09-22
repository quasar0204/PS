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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
lint n, s;
vector<int> arr;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> s;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= s) {
			cout << 1;
			return 0;
		}
	}

	int l = 0, r = 0;
	lint sum = 0;
	int ans = INF;
	while (r < n) {
		sum += arr[r++];
		if (sum < 0) {
			l = r;
			sum = 0;
			continue;
		}
		if (sum >= s) {
			while (l < r && sum - arr[l] >= s) {
				sum -= arr[l];
				l++;
			}
			ans = min(ans, r - l);
		}
	}

	if (ans == INF) ans = 0;

	cout << ans;

	//code end
	return 0;
}