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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n, k;
const int mxn = 3000;
bool dp[mxn + 1][mxn + 1];
int arrX[mxn + 1], arrY[mxn + 1];
int idxX[mxn + 1], idxY[mxn + 1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		cout << "Case #" << c << '\n';
		cin >> n >> k;

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++) {
			cin >> arrX[i];
		}

		for (int i = 1; i <= n; i++) {
			cin >> arrY[i];
		}

		for (int i = 0; i <= n; i++) {
			int sum = 0;
			cnt = 1;
			for (int j = i + 1; j <= n; j++) {
				sum += arrX[j];
				cnt++;
				if (sum <= k) {
					idxX[i] = cnt;
				}
				else
					break;
			}
		}

		for (int i = 0; i <= n; i++) {
			int sum = 0;
			cnt = 1;
			for (int j = i + 1; j <= n; j++) {
				sum += arrY[j];
				cnt++;
				if (sum <= k) {
					idxY[i] = cnt;
				}
				else
					break;
			}
		}

		dp[0][0] = true;
		dp[1][1] = true;
		for (int y = 0; y <= n; y++) {
			for (int x = 0; x <= n; x++) {
				if (dp[y][x] == false) {
					for (int s = 1; s < idxX[x]; s++)
						dp[y][x + s] = true;
					for (int s = 1; s < idxY[y]; s++)
						dp[y + s][x] = true;
				}
			}
		}

		int win = 0, lose = 0;
		for (int y = 0; y <= n; y++) {
			for (int x = 0; x <= n; x++) {
				if (dp[y][x])
					win++;
				else
					lose++;
			}
		}

		cout << win << ' ' << lose << '\n';
	}

	return 0;
}