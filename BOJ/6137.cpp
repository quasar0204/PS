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
vector<char> arr;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int l = 0, r = n - 1;
	while (cnt < n) {
		bool left = false;
		for (int i = 0; i + l < r; i++) {
			if (arr[l + i] < arr[r - i]) {
				left = true;
				break;
			}
			else if (arr[r - i] < arr[l + i])
				break;
		}
		if (left) {
			cout << arr[l];
			l++;
		}
		else {
			cout << arr[r];
			r--;
		}
		cnt++;
		if (cnt != 0 && cnt % 80 == 0) cout << '\n';
	}

	//code end
	return 0;
}