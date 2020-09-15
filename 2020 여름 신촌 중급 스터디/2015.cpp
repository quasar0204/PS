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
const int mxn = 200001;

lint tc, cnt;
int n;
int psum[mxn];
map<int, lint> m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		if (psum[i] == k) {
			cnt++;
		}

		cnt += m[psum[i] - k];

		m[psum[i]]++;
	}

	cout << cnt;
	//code end
	return 0;
}
