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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 998244353;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, k;
map<int,int> m;
vector<int> v;
int arr[1010][1010];
int ans;
bool flag = true;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	
	if (m.size() < k) {
		cout << 0;
		return 0;
	}

	for (auto x : m) {
		v.push_back(x.first);
	}

	for (int x = 1; x <= n; x++)
		arr[0][x] = 1;

	for (int y = 1; y <= k; y++) {
		for (int x = 0; x <= n; x++) {

			if (y > x)
				continue;

			if (x == y) {
				arr[y][x] = 1;
				continue;
			}

			arr[y][x] = (arr[y - 1][x - 1] + arr[y][x-1]) % MOD;
		}
	}

	do {
		int tmp = 1;
		for (int i = 0; i < k; i++) {
			tmp *= m[v[i]];
		}
		ans += tmp;
		if (ans >= MOD) {
			ans %= MOD;
		}

	} while (next_permutation(v.begin(), v.end()));
	ans /= arr[k][n] / arr[k][n-k];
	cout << ans;

	//code end
	return 0;
}