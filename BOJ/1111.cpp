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
const int mxn = 100;

int tc, cnt;
int n;
int arr[mxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n == 1) cout << "A";
	else if (n == 2) {
		if (arr[0] == arr[1]) cout << arr[0];
		else cout << "A";
	}
	else {
		int a;
		if (arr[0] != arr[1]) {
			a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
		}
		else {
			a = 1;
		}
		int b = arr[1] - a * arr[0];

		for (int i = 0; i < n - 1; i++) {
			if (arr[i + 1] != arr[i] * a + b) {
				cout << "B";
				return 0;
			}
		}

		cout << arr[n - 1] * a + b;
	}


	//code end
	return 0;
}