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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

typedef struct {
	int x;
	int y;
	int z;
} three;

int tc, cnt;
int n;
three arr[216];
vector<int> v;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	for (int x = 1; x <= 6; x++) {
		for (int y = 1; y <= 6; y++) {
			for (int z = 1; z <= 6; z++) {
				arr[x - 1 + 6 * (y - 1) + 36 * (z - 1)].x = x;
				arr[x - 1 + 6 * (y - 1) + 36 * (z - 1)].y = y;
				arr[x - 1 + 6 * (y - 1) + 36 * (z - 1)].z = z;
			}
		}
	}

	for (int i = 0; i < 216; i++) {
		if (arr[i].x == arr[i].y && arr[i].x == arr[i].z) {
			v.push_back(10000 + 1000 * arr[i].x);
			continue;
		}
		if (arr[i].x == arr[i].y || arr[i].x == arr[i].z || arr[i].y == arr[i].z) {
			v.push_back(1000 + 100 * arr[i].x);
			continue;
		}
		int m = max(arr[i].x, arr[i].y);
		m = max(m, arr[i].z);
		v.push_back(100 * m);
	}

	sort(all(v));

	//code end
	return 0;
}