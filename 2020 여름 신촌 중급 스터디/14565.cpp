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
const int mxn = 10000;

int tc, cnt;
lint n, a;

long long int mul(long long int a, long long int b) {
	if (b == 0) return 0;
	long long int t = mul(a, b / 2);
	if (b % 2 == 0) return (t + t) % n;
	return (t + t + a) % n;
}

long long int pow(long long int x) {
	if (x == 0) return 1;
	long long int t = pow(x / 2);
	if (x % 2 == 0) return mul(t, t);
	return mul(t, mul(t, a));
}


lint gcd(lint a, lint b) {
	lint M = max(a, b);
	lint m = min(a, b);

	while (true) {
		if (M % m == 0) break;
		M = M % m;
		swap(M, m);
	}

	return m;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> a;
	cout << n - a << ' ';

	if (gcd(n, a) != 1)
		cout << -1;
	else {
		lint p = n;
		lint N = n;
		for (lint i = 2; i * i <= n; i++) {
			if (N % i == 0) {
				p = p - p / i;
				while (N % i == 0) {
					N /= i;
				}
			}
		}
		if (N != 1)
			p = p - p / N;

		p--;
		
		cout << pow(p);
	}
	//code end
	return 0;
}
