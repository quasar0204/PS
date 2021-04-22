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
int n;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else {
		return gcd(y, x % y);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	int d1, d2;
	cin >> d1 >> d2;

	set<pii> s;
	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j < i; j++) {
			int g = gcd(i, j);
			s.insert({ i / g, j / g });
		}
	}

	cout << s.size() + 1;
	//code end
	return 0;
}
