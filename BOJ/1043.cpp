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
const int mxn = 51;

int tc, cnt;
int n, m;

vector<int> arr[mxn];
bool truth[mxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	int t;
	cin >> t;
	
	int cur;
	while (t--) {
		cin >> cur;
		truth[cur] = true;
	}
	int tmp;
	for (int i = 0; i < m; i++) {
		cin >> cur;
		bool flag = false;
		for (int j = 0; j < cur; j++) {
			cin >> tmp;
			arr[i].push_back(tmp);
			if (truth[tmp]) flag = true;
		}

		if (flag) {
			for (int j = 0; j < cur; j++) {
				truth[arr[i][j]] = true;
			}
		}
	}

	for (int k = 0; k < mxn; k++) {
		for (int i = 0; i < m; i++) {
			bool flag = false;
			for (int j = 0; j < arr[i].size(); j++) {
				if (truth[arr[i][j]]) flag = true;
			}

			if (flag) {
				for (int j = 0; j < arr[i].size(); j++) {
					truth[arr[i][j]] = true;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < arr[i].size(); j++) {
			if (truth[arr[i][j]]) flag = true;
		}

		if (!flag) {
			cnt++;
		}
	}

	cout << cnt;
	//code end
	return 0;
}