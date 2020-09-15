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
lint a, r, n, mod;


lint square(int n) {
	if (n == 0) {
		return 1;
	}

	lint ret;
	if (n % 2 == 0) {
		lint tmp = square(n / 2) % mod;
		ret = (tmp * tmp) % mod;
	}
	else {
		lint tmp = square(n / 2) % mod;
		ret = (tmp * tmp) % mod;
		ret = (ret * (r%mod)) % mod;
	}

	return ret;
}

lint solve(lint l, lint r, lint size) {
	if (size == 1)
		return (a*square(l)) % mod;

	if (size % 2 == 0) 
		return (solve(l, l + (size / 2) - 1, size / 2)*(square((size / 2)) + 1)) % mod;
	else
		return (solve(r, r, 1) + solve(l, l + (size / 2) - 1, size / 2)*(square((size / 2)) + 1)) % mod;
	
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> a >> r >> n >> mod;

	a = a % mod;

	cout << solve(0,n-1,n) % mod;
	

	//code end
	return 0;
}