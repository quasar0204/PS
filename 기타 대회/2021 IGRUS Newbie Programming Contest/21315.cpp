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
const int mxn = 1010;

int tc, cnt;
int n, k;
int arr[mxn];
deque<int> dq;

deque<int> shack(int k) {
	int start = n - 1;
	deque<int> ret, tmp;

	while (k >= 0) {
		int t = (1 << k);
		
		for (int i = 0; i < t; i++) {
			tmp.push_front(dq.back());
			dq.pop_back();
		}

		while (!dq.empty()) {
			ret.push_front(dq.back());
			dq.pop_back();
		}

		while (!tmp.empty()) {
			dq.push_front(tmp.back());
			tmp.pop_back();
		}

		k--;
	}

	while (!dq.empty()) {
		ret.push_front(dq.back());
		dq.pop_back();
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int a = 1; (1 << a) < n; a++) {
		for (int b = 1; (1 << b) < n; b++) {
			dq.clear();
			for (int i = 1; i <= n; i++)
				dq.push_back(i);

			dq = shack(a);
			dq = shack(b);

			bool flag = true;
			for (int i = 0; i < n; i++) 
				if (arr[i] != dq[i]) {
					flag = false;
					break;
				}
			if (flag) {
				cout << a << ' ' << b;
				return 0;
			}
		}
	}


	return 0;
}
