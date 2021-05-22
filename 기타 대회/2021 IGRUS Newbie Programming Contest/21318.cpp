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
const int mxn = 101010;

int tc, cnt;
int n;
int arr[mxn];
int psum[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	arr[n] = -1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] < arr[i - 1]) psum[i] = 1;
		psum[i] += psum[i - 1];
	}
	int q;
	int a, b;
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << psum[b - 1] - psum[a - 1] << '\n';
	}
	
	


	return 0;
}
