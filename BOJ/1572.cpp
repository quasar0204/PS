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
int n, k;

lint fenwick[66666];
int arr[66666];
lint ans;

int sum(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += fenwick[idx];
		idx -= idx&-idx;
	}
	return ret;
}

void update(int idx, int val) {
	while (idx < 66666) {
		fenwick[idx] += val;
		idx += (idx & -idx);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;
	
	int tmp;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	for (int i = 0; i < k; i++)
		update(arr[i] + 1, 1);
	
	int l, r;
	int mid, s;
	for (int i = k; i <= n; i++) {
		l = 0, r = 1 << 16;

		while (l < r) {
			mid = (l + r) / 2;
			s = sum(mid);
			if (s >= (k + 1) / 2) r = mid;
			else l = mid + 1;
		}
		ans += l - 1;
		if (i == n) 
			break;

		update(arr[i] + 1, 1);
		update(arr[i - k] + 1, -1);
	}

	cout << ans;
	
	//code end
	return 0;
}