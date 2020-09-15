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
const int mxn = 200000+1;

int tc, cnt;
int n, k, q;
lint arr[mxn];
lint sum[mxn];
multiset<lint> ms;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';

		cin >> n >> k >> q;

		memset(sum, -1, sizeof(sum));
		lint _sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			_sum += arr[i];

			if (i >= k) {
				ms.insert(_sum);
				sum[i] = _sum;
				_sum -= arr[i - k + 1];
			}
		}
		multiset<lint>::iterator it = ms.begin();
		for (int i = 1; i <= (n - k + 1) / 2; i++)
			it++;

		cout << *it << ' ';
		int a, b;
		for (int i = 0; i < q; i++) {
			cin >> a >> b;

			for (int j = a; j <= min(a + k - 1, n); j++) {
				if (sum[j] == -1) continue;

				lint tmp = sum[j];
				sum[j] = sum[j] - arr[a] + b;
				ms.insert(sum[j]);
				if (*it == tmp) it--;
				ms.erase(ms.lower_bound(tmp));


				if (tmp <= *it && sum[j] >= *it) it++;
				else if (tmp >= *it && sum[j] <= *it) it--;
			}
			arr[a] = b;
			cout << *it << ' ';
		}
		cout << endl;
	}

	return 0;
}