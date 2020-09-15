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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
vector<int> ans;
int arr[1000000];
int lis[1000000];

int getIndex(int x) {
	return lower_bound(all(ans), x) - ans.begin();
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> n;

	int idx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (ans.empty() || ans.back() < arr[i]) {
			ans.push_back(arr[i]);
			lis[i] = ans.size();
		}
		else {
			idx = getIndex(arr[i]);
			ans[idx] = arr[i];
			lis[i] = idx + 1;
		}
	}

	cout << ans.size() << '\n';
	vector<int> find_lis;

	for (int i = n - 1; i >= 0; i--) {
		if (lis[i] == ans.size()) {
			find_lis.push_back(ans.back());
			ans.pop_back();
		}
	}

	for (int i = find_lis.size() - 1; i >= 0; i--) {
		cout << find_lis[i] << ' ';
	}

	//code end
	return 0;
}