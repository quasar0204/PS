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
int R, S, E;

typedef struct {
	int l;
	int r;
	int h;
} node;
node arr[1000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	
	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';
		cin >> R >> S >> E;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i].l >> arr[i].r >> arr[i].h;

		double ans = E - S;

		for (int i = 0; i < n; i++) {
			if (arr[i].l > E)
				break;

			if (arr[i].h >= R) {
				ans += R * PI;
				ans += (arr[i].h - R) * 2;
				ans -= 2 * R;
			}
			else {
				ans += 2 * abs(acos((double)(R - arr[i].h)/(double)R))*R;
				ans -= 2 * sqrt(R*R-(R- arr[i].h)*(R - arr[i].h));
			}
		}

		cout.precision(32);
		cout << ans << '\n';

	}


	//code end
	return 0;
}