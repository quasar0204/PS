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
const int mxn = 10000;

int tc, cnt;
int n;
vector<int> arr;
vector<int> arr2;
vector<int> arr3;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> tc;

	int t = 0;
	for (int i = 1; i <= 1000; i++) {
		arr.push_back(t += i);
		if (t >= 1000) break;
	}

	for (int i = 0; i < (int)arr.size(); i++) {
		for (int j = 0; j < (int)arr.size(); j++) {
			arr2.push_back(arr[i] + arr[j]);
		}
	}
		
	for (int i = 0; i < (int)arr2.size(); i++) {
		for (int j = 0; j < (int)arr.size(); j++) {
			arr3.push_back(arr2[i] + arr[j]);
		}
	}
	sort(all(arr3));

	while (tc--) {
		cin >> n;

		if (n == *lower_bound(all(arr3), n))
			cout << "1\n";
		else
			cout << "0\n";

	}



	return 0;
}
