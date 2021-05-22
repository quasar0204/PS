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
const int mxn = 22;

int tc, cnt;
int n;
int s[mxn], b[mxn], k;

struct node {
	int a, b, c;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> s[i] >> b[i];
	cin >> k;

	int ans = 987654321;
	queue<node> q;
	q.push({ 1,0,0 });

	while (!q.empty()) {
		if (q.front().a == n) {
			ans = min(ans, q.front().b);
			q.pop();
			continue;
		}
		else if (q.front().a > n) {
			q.pop();
			continue;
		}
		q.push({ q.front().a + 1, q.front().b + s[q.front().a], q.front().c });
		q.push({ q.front().a + 2, q.front().b + b[q.front().a], q.front().c });
		if (q.front().c == 0) q.push({ q.front().a + 3, q.front().b + k, 1 });
		q.pop();
	}

	cout << ans;

	return 0;
}
