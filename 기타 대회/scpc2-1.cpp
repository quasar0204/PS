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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 200000;

int tc, cnt;
int n;

vector<int> a;
bool visita[mxn], visitb[mxn];
multiset<int> ms;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << '\n';
		cin >> n;

		a.resize(n);
		memset(visita, false, sizeof(visita));
		memset(visitb, false, sizeof(visitb));

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int b;
		for (int i = 0; i < n; i++) {
			cin >> b;
			ms.insert(b);
		}
		sort(all(a));
		

		lint ans = 0;
		int _mxn = 0;
		for (int i = 0; i < n; i++) {
			multiset<int>::iterator lo = ms.lower_bound(a[i]);
			multiset<int>::iterator hi = ms.upper_bound(a[i]);

			if (lo != ms.end() && *lo == a[i]) {
				ans += abs(a[i] - *lo);
				_mxn = max(_mxn, abs(a[i] - *lo));
				ms.erase(lo);
				continue;
			}

			lo--;
			if (hi == ms.end() || (lo != ms.end() && hi != ms.end() &&  abs(a[i] - *lo) <= abs(a[i] - *hi))) {
				ans += abs(a[i] - *lo);
				_mxn = max(_mxn,abs(a[i] - *lo));
				ms.erase(lo);
			}
			else {
				ans += abs(a[i] - *hi);
				_mxn = max(_mxn, abs(a[i] - *hi));
				ms.erase(hi);
			}
		}

		ans -= _mxn;
		
		cout << ans << endl;

	}

	return 0;
}