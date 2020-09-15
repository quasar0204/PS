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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, k, r;
int arr[101010];
int sum;
int ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n >> k >> r;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] = 1;
	}

	for (int i = 1; i <= r; i++) {
		sum += arr[i];
	}
	if (sum == 0) {
		arr[r] = 1;
		arr[r - 1] = 1;
		sum += 2;
		ans += 2;
	}
	if (sum == 1) {
		if (arr[r] == 0) {
			arr[r] = 1;
		}
		else {
			arr[r - 1] = 1;
		}
		sum += 1;
		ans += 1;
	}

	for (int i = r + 1; i <= n; i++) {
		if (arr[i - r] == 1) {
			sum -= 1;
		}
		if (arr[i] == 1) {
			sum += 1;
		}

		if (sum < 2) {
			arr[i] = 1;
			sum += 1;
			ans += 1;
		}
	}

	cout << ans;


	//code end
	return 0;
}