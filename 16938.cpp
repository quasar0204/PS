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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n, l, r, x;
int in[1 << 15];
int arr[15];
int sum[1 << 15];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++)
		in[1 << i] = arr[i];

	

	for (int idx = 0; idx < n; idx++) {
		for (int i = (1 << idx); i < (1 << (idx + 1)); i++) {
			sum[i] = in[1 << idx] + sum[(i & ((1 << idx) - 1))];
		}
	}

	for (int idx = 0; idx < n; idx++) {
		for (int i = (1 << idx); i < (1 << (idx + 1)); i++) {
			if (sum[i] >= l && sum[i] <= r) {
				if (in[1 << idx] - in[i & (-i)] >= x)
					cnt++;
			}
		}
	}

	cout << cnt;

	//code end
	return 0;
}
