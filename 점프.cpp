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
lint arr[mxn];
const int mxn = 1000000;
lint ans;

void solve(lint num) {
	lint* _find = lower_bound(arr + 1, arr + mxn, num);


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	for (lint i = 1; i < mxn; i++) {
		arr[i] = i * (i + 1) / 2;
	}

	cin >> tc;
	lint x, y;
	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';

		cin >> x >> y;

		if (x == *lower_bound(arr + 1, arr + mxn, x)) {
			cout << lower_bound(arr + 1, arr + mxn, x) - arr << '\n';
			continue;
		}

		if (y >= *(lower_bound(arr + 1, arr + mxn, x) + 1)) {
			cout << lower_bound(arr + 1, arr + mxn, x) + 1 - arr << '\n';
			continue;
		}



	}

	//code end
	return 0;
}