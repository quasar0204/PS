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
const int mxn = 2020;

lint tc, cnt[mxn];
lint n, m;
lint tmp[mxn][mxn];
int num[mxn][mxn];
int l[mxn][mxn];
vector<lint> arr[mxn];

pii find(int y, int x) {
	int level = l[y][x];
	int here = num[y][x];
	here -= cnt[level];
	here %= (int)arr[level].size();
	here = (here + (int)arr[level].size()) % (int)arr[level].size();

	return { level, here };
}

void _swap(int y, int x) {
	pii p1, p2, p3, p4;
	p1 = find(y + 1, x);
	p2 = find(y, x);
	p3 = find(y, x + 1);
	p4 = find(y + 1, x + 1);

	int tmp = arr[p4.first][p4.second];
	arr[p4.first][p4.second] = arr[p3.first][p3.second];
	arr[p3.first][p3.second] = arr[p2.first][p2.second];
	arr[p2.first][p2.second] = arr[p1.first][p1.second];
	arr[p1.first][p1.second] = tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; y++) 
		for (int x = 0; x < n; x++)
			cin >> tmp[y][x];
	
	for (int i = 0; i < n / 2; i++) {
		int id = 0;
		for (int x = i; x < n - i; x++) {
			arr[i].push_back(tmp[i][x]);
			num[i][x] = id++;
			l[i][x] = i;
		}
		for (int y = i + 1; y < n - i; y++) {
			arr[i].push_back(tmp[y][n - 1 - i]);
			num[y][n - 1 - i] = id++;
			l[y][n - 1 - i] = i;
		}
		for (int x = n - 2 - i; x >= i; x--) {
			arr[i].push_back(tmp[n - 1 - i][x]);
			num[n - 1 - i][x] = id++;
			l[n - 1 - i][x] = i;
		}
		for (int y = n - 2 - i; y > i; y--) {
			arr[i].push_back(tmp[y][i]);
			num[y][i] = id++;
			l[y][i] = i;
		}
	}

	lint a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			cnt[l[b - 1][b - 1]] += c;
		}
		else if (a == 2) {
			_swap(b - 1, c - 1);
		}
		else {
			pii here = find(b - 1, c - 1);
			cout << arr[here.first][here.second] << '\n';
		}
	}


	return 0;
}
