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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

#define min2(x,y) x>y? y:x
#define max2(x,y) x<y? y:x

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;

const lint max_int = 100000000000000;
vector<lint> v;
lint A, B;
lint ans;
typedef long long ll;
bool isprime[10000001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	isprime[1] = true;
	for (int i = 2; i <= 10000000; i++)
	{
		if (isprime[i])
			continue;
		for (int j = i + i; j <= 10000000; j += i)
			isprime[j] = true;
	}
	ll a, b;
	cin >> a >> b;


	int cnt = 0;
	for (int i = 2; i <= 10000000; i++) {
		if (isprime[i])
			continue;
		ll now, next;
		now = 1LL * i*i;
		while (1)
		{
			if (now > b)
				break;

			if (a <= now && now <= b)
				cnt++;
			next = 1LL * i*now;
			if (next%now != 0)
				break;
			now = next;
		}
	}
	cout << cnt;

	//code end
	return 0;
}