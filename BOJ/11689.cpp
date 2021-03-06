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
const int mxn = 1000001;

int tc, cnt;
lint n;
bool p[mxn];
vector<lint> k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	for (int i = 2; i * i < mxn; i++) {
		if (!p[i]) {
			for (int j = i + i; j < mxn; j += i) {
				p[j] = true;
			}
		}
	}

	lint N = n;
	for (int i = 2; i < mxn; i++) {
		if (!p[i] && (n % i) == 0) {
			k.push_back(i);
			while (N % i == 0) {
				N /= i;
			}
		}
	}

	lint ans = n;
	for (auto x : k) {
		ans = ans - ans / x;
	}
	if (N != 1)
		ans = ans - ans / N;

	cout << ans;

	//code end
	return 0;
}
