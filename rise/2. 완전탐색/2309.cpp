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
const int mxn = 10000;

int tc, cnt;
int n;
int arr[9];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int i, j;
	int sum = 0;

	for (i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	sum -= 100;

	for (i = 0; i < 9; i++) {
		bool flag = false;
		for (j = 0; j < 9; j++) {
			if (sum == arr[i] + arr[j]) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int k = 0; k < 9; k++) {
		if (k == i || k == j) continue;
		cout << arr[k] << '\n';
	}


	return 0;
}
