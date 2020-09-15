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

lint tc, cnt;
int n;
int arr[1000000];
int tmp[1000000];

void merge(int l, int m, int r) {
	int idx1 = l;
	int idx2 = m;
	int idx3 = l;

	while (idx1 < m && idx2 < r) {
		if (arr[idx2] > arr[idx1]) {
			tmp[idx3] = arr[idx1];
			idx3++; idx1++;
		}
		else {
			tmp[idx3] = arr[idx2];
			idx3++; idx2++;
			cnt += (m - idx1);
		}
	}

	while (idx1 < m) {
		tmp[idx3] = arr[idx1];
		idx3++; idx1++;
	}

	while (idx2 < r) {
		tmp[idx3] = arr[idx2];
		idx3++; idx2++;
	}

	for (int idx = l; idx < r; idx++) {
		arr[idx] = tmp[idx];
	}
}

void merge_sort(int l, int r) {
	if (r - l == 1)
		return;

	int mid = (r + l) / 2;

	merge_sort(l, mid);
	merge_sort(mid, r);
	merge(l, mid, r);

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
	merge_sort(0, n);

	cout << cnt;

	//code end
	return 0;
}