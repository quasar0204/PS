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
const int mxn = 100000 + 1;

int tc, cnt;
int n;
vector<int> arr;

int fastMaxSum(const vector<int>&A, int lo, int hi) {
	if (lo == hi) return A[lo];

	int mid = (lo + hi) / 2;

	int left = -INF, right = -INF, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += A[i];
		left = max(left, sum);
	}

	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += A[j];
		right = max(right, sum);
	}

	int single = max(fastMaxSum(A, lo, mid),
		fastMaxSum(A, mid + 1, hi));

	return max(left + right, single);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << fastMaxSum(arr, 0, n-1);

	//code end
	return 0;
}
