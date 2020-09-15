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
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
int d1, d2;
bool check[2001][2001];
int ans;

int gcd(int x, int y) {
	if (y)
		return gcd(y, x % y);
	
	return x;
}

void solve(int x) {
	for (int i = 1; i < x; i++) {
		int g = gcd(x, i);

		if (check[i / g][x / g])
			continue;
		else {
			check[i / g][x / g] = true;
			ans++;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> d1 >> d2;

	for (int i = d1; i <= d2; i++)
		solve(i);

	cout << ans + 1;
	//code end
	return 0;
}