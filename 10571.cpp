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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
double arr1[101];
double arr2[101];
int arrw[101];
int arrc[101];
int mxn;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i] >> arr2[i];
		}
		arrw[0] = 1;
		arrc[0] = 1;
		for (int i = 1; i < n; i++) {
			if (arr1[i - 1] < arr1[i]) {
				arrw[i] = 1;
			}
			else {
				arrw[i] = -1;
			}
			if (arr2[i - 1] > arr2[i]) {
				arrc[i] = 1;
			}
			else {
				arrc[i] = -1;
			}
			if (!(arrc[i] == -1 && arrw[i] == -1)) {
				arrc[i] *= arrw[i];
			}
		}
		mxn = 0;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arrc[i] == 1) {
				cnt++;
			}
			else {
				if (cnt > mxn) {
					mxn = cnt;
				}
				cnt = 1;
			}
		}
		if (cnt > mxn) {
			mxn = cnt;
		}
		cout << mxn << '\n';
	}
	//code end
	return 0;
}