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
int b, p;
int arrb[14];
int arrp[14];
int w[1 << 14];
set<int> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> b >> p;
	for (int i = 0; i < b; i++) {
		cin >> arrb[i];
	}

	for (int i = 0; i < p; i++) {
		cin >> arrp[i];
	}

	w[0] = 0;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < 1 << i; j++) {
			w[(1 << i) | j] = arrp[i] + w[j];
		}
	}

	for (int R = 0; R < 1 << p; R++) {
		for (int L = 0; L <= R; L++) {
			if ((L & R) == 0 && w[L] == w[R]) {
				for (int i = 0; i < b; i++) {
					ans.insert(arrb[i] + 2 * w[R]);
				}
			}
		}
	}

	for (auto i : ans)
		cout << i << '\n';



	//code end
	return 0;
}