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
const int mxn = 1000000 + 1;

int tc, cnt;
int n;

int place[mxn];
priority_queue<int> pq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		int x, g;
		cin >> x >> g;
		place[x] += g;
	}

	int l, p;
	cin >> l >> p;
	
	int car = 0;
	while (car < l) {
		if (place[car]) pq.push(place[car]);
		if (p == 0) {
			if (pq.empty()) {
				cout << -1;
				return 0;
			}
			else {
				p += pq.top();
				pq.pop();
				cnt++;
			}
		}
		p--;
		car++;
	}


	cout << cnt;
	//code end
	return 0;
}