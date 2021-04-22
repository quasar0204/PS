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
vector<lint> arrp, arrn;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> n;
		arrp.clear();
		arrn.clear();
		bool zflag = false;
		int onecnt = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num > 0) arrp.push_back(num);
			else if (num < 0) arrn.push_back(-num);
			else zflag = true;
		}

		sort(all(arrp));
		sort(all(arrn));
		lint ans = -LINF;
		int idxp = arrp.size() - 1;
		int idxn = arrn.size() - 1;

		if (zflag) ans = 0LL;
		if (arrp.size() >= 5) {
			ans = max(ans, arrp[idxp] * arrp[idxp - 1] * arrp[idxp - 2] * arrp[idxp - 3] * arrp[idxp - 4]);
		}
		if (arrp.size() >= 1 && arrn.size() >= 4) {
			ans = max(ans, arrn[idxn] * arrn[idxn - 1] * arrn[idxn - 2] * arrn[idxn - 3] * arrp[idxp]);
		}
		if (arrp.size() >= 3 && arrn.size() >= 2) {
			ans = max(ans, arrn[idxn] * arrn[idxn - 1] * arrp[idxp] * arrp[idxp - 1] * arrp[idxp - 2]);
		}
		if (arrp.size() >= 2 && arrn.size() >= 3) {
			ans = max(ans, -arrn[0] * arrn[1] * arrn[2] * arrp[0] * arrp[1]);
		}
		if (arrn.size() >= 5) {
			ans = max(ans, -arrn[0] * arrn[1] * arrn[2] * arrn[3] * arrn[4]);
		}
		if (arrp.size() >= 4 && arrn.size() >= 1) {
			ans = max(ans, -arrp[0] * arrp[1] * arrp[2] * arrp[3] * arrn[0]);
		}
		
		cout << ans << '\n';
	}


	//code end
	return 0;
}