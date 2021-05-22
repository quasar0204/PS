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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, c;

	cin >> a >> b >> c;
	priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
	pq.push(a * b);
	pq.push(a * c);
	pq.push(b * c);
	pq.push(a * b * c);

	int h = -1, j = -1;
	while (!pq.empty()) {
		if (pq.top() % 2) {
			if (h == -1) h = pq.top();
		}
		else
			if (j == -1) j = pq.top();
		pq.pop();
	}

	if (h != -1) cout << h;
	else cout << j;

	return 0;
}
