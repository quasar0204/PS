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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
int n;
vector<int> arr1, arr2;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";

		cin >> n;
		arr1.resize(n);
		arr2.resize(n);

		for (int i = 0; i < n; i++) 
			cin >> arr1[i];
		
		for (int i = 0; i < n; i++)
			cin >> arr2[i];

		sort(all(arr1), greater<int>());
		sort(all(arr2), less<int>());

		lint ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (lint)arr1[i] * arr2[i];
		}

		cout << ans << '\n';
	}

	//code end
	return 0;
}