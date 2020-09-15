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
bool visit[1001];
int check[1001][170];
vector<int> prime;
int arr[170];
lint ans;

lint power(lint x, lint y) {
	lint ret = 1;

	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= MOD;
		}
		x = (x*x) % MOD;
		y /= 2;
	}
	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	int idx = 0;
	int tmp;
	for (int num = 2; num <= 1000; num++) {
		if (!visit[num]) {
			prime.push_back(num);
			for (int next = num; next <= 1000; next += num) {
				visit[next] = true;
				
				tmp = next;
				while (tmp % num == 0) {
					if (check[next][idx] == 0)
						check[next][idx] = 1;
					check[next][idx] = (check[next][idx] * prime[idx]) % MOD;
					tmp /= num;
				}
			}
			idx++;
		}
	}

	cin >> tc;
	while (tc--) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;

			for (idx = 0; idx < prime.size(); idx++) {
				arr[idx] = max(arr[idx], check[tmp][idx]);
			}
		}

		ans = 1;

		for (int idx = 0; idx < prime.size(); idx++) {
			if (arr[idx])
				ans = (ans * arr[idx]) % MOD;
		}

		
		cout << ans << '\n';
	}

	//code end
	return 0;
}