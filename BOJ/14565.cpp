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
lint n;
lint a;

lint mul(lint x, lint y) {
	if (y >= 0)
		return y % x;

	return (y + ((-y/x) + 1)*x) % x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> a;

	cout << n - a << ' ';

	lint N = n, A = a, t1 = 0, t2 = 1;

	while (A > 0) {
		lint q = N / A, r = N - q * A, t = t1 - q * t2;
		N = A;
		A = r;
		t1 = t2;
		t2 = t;
	}

	if (N == 1) {
		cout << mul(n, t1);
	}
	else {
		cout << -1;
	}

	
	//code end
	return 0;
}