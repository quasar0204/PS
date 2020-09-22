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
const int mxn = 1001;

int tc, cnt;
int r, n;
vector<int> arr;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	while (true) {
		cin >> r >> n;
		if (r == -1) break;

		arr.resize(mxn, 1);
		cnt = 0;
		int now;
		for (int i = 0; i < n; i++) {
			cin >> now;
			arr[now] = 0;
		}

		for (int i = 0; i < mxn; i++) {
			if (arr[i] == 0) {
				int right = i;
				for (int j = i; j < i + r && j < mxn; j++) {
					if (arr[j] == 0) right = j;
				}
				for (int j = i; j <= right + r && j < mxn; j++) {
					arr[j] = 1;
				}
				cnt++;
			}
		}

		cout << cnt << '\n';

	}

	//code end
	return 0;
}