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
const int mxn = 300001;

int tc, cnt;
int n;

class Seg {
public:
	int leaf = 1;
	vector<int> tree;

	int init(const vector<int >& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else {
				int now = 0;
				if (arr[0] < 0) now = -2 * INF;
				return tree[node] = now;
			}
		}

		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, node * 2);
		int rightMin = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftMin, rightMin);
	}

	int init(const vector<int>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		return init(arr, 0, leaf - 1, 1);
	}


	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return 0;

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return max(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	int solve(int left, int right, int val) {
		if (left == right) {
			return left;
		}

		int mid = (left + right) / 2;

		int leftPart = query(left, mid);
		if (leftPart >= val) {
			return solve(left, mid, val);
		}
		else {
			return solve(mid+1, right, val);
		}
	}

	int func(int a, int b) {
		return max(a, b);
	}
};

int dp[mxn];

vector<int> marr, Marr;
Seg mseg, Mseg;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> n;

	fill(dp, dp + mxn, 2*INF);

	marr.resize(n);
	Marr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> marr[i];
		Marr[i] = -marr[i];
	}
	
	mseg.init(marr);
	Mseg.init(Marr);

	dp[1] = 0;
	for (int i = 1; i < n; i++) {
		int down = mseg.solve(i + 1, n, marr[i - 1]);
		int up = Mseg.solve(i + 1, n, Marr[i - 1]);
		if (down != n && marr[i - 1] == marr[down] && marr[i-1] > marr[down - 1]) down++;
		if (up != n && Marr[i - 1] == Marr[up] && Marr[i-1] > Marr[up-1]) up++;

		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (down <= n) dp[down] = min(dp[down], dp[i] + 1);
		if (up <= n) dp[up] = min(dp[up], dp[i] + 1);
	}
	
	cout << dp[n];

	//code end
	return 0;
}