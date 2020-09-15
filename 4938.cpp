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

int tc, cnt;
int n;
const int m = 123456 * 2 + 1;

int arr[m];
bool prime[m];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	prime[1] = true;
	for (int i = 2; i < m; i++) {
		if (!prime[i]) {
			for (int j = i * 2; j < m; j += i)
				prime[j] = true;
		}
	}

	for (int i = 2; i < m; i++) {
		if (!prime[i]) {
			arr[i] = arr[i - 1] + 1;
		}
		else {
			arr[i] = arr[i - 1];
		}
	}

	while (true) {
		cin >> n;
		if (n == 0)
			break;
		cout << arr[n * 2] - arr[n] << '\n';
	}
	//code end
	return 0;
}