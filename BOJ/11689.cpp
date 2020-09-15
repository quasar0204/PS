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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
lint n;
bool prime[1000001];
vector<lint> k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	for (int i = 2; i < 1000001; i++) {
		if (!prime[i]) {
			for (int j = i + i; j < 1000001; j += i)
				prime[j] = true;
		}
	}
	
	lint N = n;
	for (int i = 2; i < 1000001; i++) {
		if (N == 1)
			break;
		if (!prime[i]) {
			if (N % i == 0)
				k.push_back(i);
			while ((N % i) == 0) {
				N /= i;
			}
		}
	}

	lint ans = n;
	for (int i = 0; i < k.size(); i++) {
		ans = ans - ans / k[i];
	}
	if (N != 1)
		ans = ans - ans / N;
	
	cout << ans;
	//code end
	return 0;
}