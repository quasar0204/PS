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
int n, m;
int min6, min1;
int ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;
	min6 = min1 = INF;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		min6 = min(a, min6);
		min1 = min(b, min1);
	}

	min6 = min(min6, min1 * 6);

	ans += (n / 6) * min6;
	n %= 6;
	ans += min(n * min1, min6);

	cout << ans;
	//code end
	return 0;
}