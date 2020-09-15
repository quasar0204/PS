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
lint A, B, C;

lint solve(lint a, lint b, lint r) {
	if (b == 0)
		return r*1 % C;
	if (b == 1)
		return (r % C)*(a % C) % C;

	lint ret = r;
	if (b % 2 == 0) {
		lint tmp = solve(a, b / 2, r) % C;
		ret = ((r %C) * (tmp * tmp %C)) % C;
	}
	else {
		lint tmp = solve(a, b / 2 , r) % C;
		ret = (r%C) * (((tmp * tmp) %C) * (a % C) % C);
	}
	return ret % C;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> A >> B >> C;

	cout << solve(A, B, 1);

	//code end
	return 0;
}