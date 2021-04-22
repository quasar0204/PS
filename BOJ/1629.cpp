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

int tc, cnt;
int n;

lint A, B, C;

lint solve(lint a, lint b, lint c) {
	if (b == 0)
		return 1LL;
	if (b == 1)
		return a;

	lint tmp = solve(a, b / 2, c) % c;
	lint ret = (tmp * tmp) % c;
	if (b % 2) {
		ret = (ret * a) % c;
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> A >> B >> C;

	cout << solve(A % C, B, C);
	//code end
	return 0;
}