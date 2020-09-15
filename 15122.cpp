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
int arr[7];
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n;
	int idx = 0;
	while (n) {
		arr[idx] = n % 10;
		n /= 10;
		++idx;
	}
	
	arr[0] += 1;
	for (int i = 0; i < idx; i++) {
		if (arr[i] == 10) {
			arr[i + 1] += 1;
			arr[i] = 1;
		}
	}

	for (int i = 6; i >= 0; i--) {
		if (arr[i]) {
			cout << arr[i];
		}
	}
	//code end
	return 0;
}