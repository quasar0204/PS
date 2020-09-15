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

bool prime[1000001];
int n;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
//code start
	cin >> n;

	for (int i = 2; i*i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			prime[j] = true;
		}
	}

	while (n >= 3) {
		for (int i = 2; i <= n/2; i++) {
			if (prime[i])
				continue;
			
			if (prime[n - i]) {
				continue;
			}
			
			cnt++;
			n = (n - i) - i;
			break;
		}
	}
	cout << cnt;
//code end
	return 0;
}