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
int n, m;

int getIndex(int x, vector<int>& v) {
	return lower_bound(all(v), x) - v.begin();

}

int solve(vector<int>& a, vector<int>& b) {
	vector<int> j;
	vector<int> idx_j;
	int ret = 0;
	int idx_a = 0, idx_b = 0;

	while (idx_a < a.size() || idx_b < b.size()) {
		if (idx_a == a.size() || (idx_b != b.size() && b[idx_b] <= a[idx_a])) {
			j.push_back(b[idx_b]);
			idx_j.push_back(b[idx_b]);
			idx_b++;
		}
		else {
			j.push_back(a[idx_a]);
			idx_j.push_back(a[idx_a]);
			idx_a++;
		}
	}

	sort(all(idx_j));
	idx_j.erase(unique(all(idx_j)), idx_j.end());

	vector<int> dp;
	dp.resize(idx_j.size());

	int _max;
	for (int y = 0; y < j.size(); y++) {
		_max = 0;
		for (int x = y - 1; x >= 0; x--) {
			if (j[y] > j[x]) {
				_max = max(dp[getIndex(j[x], idx_j)], _max);
			}
		}
		dp[getIndex(j[y], idx_j)] = max(dp[getIndex(j[y], idx_j)], _max + 1);
		ret = max(ret, dp[getIndex(j[y], idx_j)]);
	}

	return ret;
}

vector<int> arr1, arr2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	while (tc--) {
		cin >> n >> m;
		
		arr1.resize(n);
		arr2.resize(m);

		for (int i = 0; i < n; i++)
			cin >> arr1[i];

		for (int i = 0; i < m; i++)
			cin >> arr2[i];
		
		cout << solve(arr1, arr2) << '\n';

	}

	//code end
	return 0;
}