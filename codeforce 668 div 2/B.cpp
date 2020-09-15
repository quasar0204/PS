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

lint solve() {
	vector<int> arr;
	arr.resize(n);
	lint ret = 0;
	stack<int> p;
	deque<int> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0)
			p.push(i);
		else if (arr[i] < 0)
			m.push_back(i);
	
	}
	
	while (!p.empty() || !m.empty()) {
		int ptop = p.top();
		int mtop = m.back();

		if (ptop > mtop) {
			while (arr[ptop] > 0) {
				int mfront = m.front();
				int tmp = min(-arr[mfront], arr[ptop]);
				arr[mfront] += tmp;
				arr[ptop] -= tmp;
				ret += tmp;
				if (arr[mfront] == 0) {
					m.pop_front();
					if (p.empty() || m.empty()) break;
					mfront = m.front();
				}

			}
			if (p.empty() || m.empty()) break;
			p.pop();
			if (p.empty() || m.empty()) break;
			ptop = p.top();
		}
		else if (ptop < mtop) {
			while (arr[mtop] < 0) {
				int tmp = min(-arr[mtop], arr[ptop]);
				arr[mtop] += tmp;
				arr[ptop] -= tmp;
				if (arr[ptop] == 0) {
					p.pop();
					if (p.empty() || m.empty()) break;
					ptop = p.top();
				}

			}
			if (p.empty() || m.empty()) break;
			m.pop_back();
			if (p.empty() || m.empty()) break;
			mtop = m.back();
		}
	}

	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> n;

		cout << solve() << '\n';
	}

	//code end
	return 0;
}