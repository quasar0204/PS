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
const int mxn = 3*1000000;

int tc, cnt;
int n;

int his[mxn];
int arr[mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	int l, range, damage;
	int mine;
	cin >> l >> range >> damage;
	cin >> mine;

	for (int i = 0; i < l; i++) {
		cin >> arr[i];
	}
	lint sum = 0;
	for (int i = 0; i < l; i++) {
		if (his[cnt] != 0) {
			his[cnt] = 0;
			sum -= damage;
		}

		if (arr[i] > sum + damage) {
			if (mine-- == 0) {
				cout << "NO";
				return 0;
			}
		}
		else {
			his[cnt] = damage;
			sum += damage;
		}
		cnt = (cnt + 1) % range;
	}
	


	cout << "YES";
	//code end
	return 0;
}