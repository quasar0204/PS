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
int n, w;

typedef struct {
	string name;
	int vol, need;
} node;

node arr[100];
int dp[1001][100];
vector<string> ans;

int solve(int cap, int item) {
	if (item == n)
		return 0;

	int& ret = dp[cap][item];

	if (ret != -1)
		return ret;

	ret = solve(cap, item + 1);

	if (cap >= arr[item].vol) {
		ret = max(ret, arr[item].need + solve(cap - arr[item].vol, item + 1));
	}

	return ret;
}

void findName(int cap, int item) {
	if (item == n)
		return;

	if (solve(cap, item) == solve(cap, item + 1)) {
		findName(cap, item + 1);
	}
	else {
		ans.push_back(arr[item].name);
		findName(cap - arr[item].vol, item + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	while (tc--) {
		cin >> n >> w;
		memset(dp, -1, sizeof(dp));
		ans.clear();

		for (int i = 0; i < n; i++) {
			cin >> arr[i].name >> arr[i].vol >> arr[i].need;
		}

		cout << solve(w, 0) << ' ';

		findName(w, 0);

		cout << ans.size() << '\n';

		for (auto s : ans)
			cout << s << '\n';
	}
	//code end
	return 0;
}