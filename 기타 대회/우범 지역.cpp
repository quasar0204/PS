#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define _USE_MATH_DEFINES

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

typedef struct _p{
	double x, y;
	double deg;
	double p;

	bool operator<(_p& rhs) {
		return deg < rhs.deg;
	}
} point;

int tc, cnt;
int n;

point arr[100000];
point D;
double sum[100000];

double getDeg(double pi) {
	if (pi < 0)
		return pi + 2 * M_PI;
	
	if (pi >= 2 * M_PI)
		return pi - 2 * M_PI;

	return pi;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i].x;
		}

		for (int i = 0; i < n; i++)
			cin >> arr[i].y;

		for (int i = 0; i < n; i++)
			cin >> arr[i].p;

		cin >> D.x >> D.y;

		for (int i = 0; i < n; i++) {
			arr[i].deg = getDeg(atan2(arr[i].y - D.y, arr[i].x - D.x));
		}

		double ans = 0.0;
		for (int i = 0; i < n; i++) {
			double p1 = 0.0, p2 = 0.0;
			for (int j = 0; j < n; j++) {
				if (fabs(arr[i].deg - arr[j].deg) >= M_PI / 2.0) {
					if ((getDeg(arr[i].deg - arr[j].deg) >= M_PI / 2.0) && (getDeg(arr[i].deg - arr[j].deg) <= M_PI)) {
						p1 += arr[j].p;
					}
					else if ((getDeg(arr[j].deg - arr[i].deg) >= M_PI / 2.0) && (getDeg(arr[j].deg - arr[i].deg) <= M_PI)) {
						p2 += arr[j].p;
					}
				}
			}
			ans += arr[i].p * p1 * p2;
		}

		cout << fixed;
		cout.precision(8);
		cout << ans / 3 << '\n';

	}

	return 0;
}