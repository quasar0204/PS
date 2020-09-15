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

#define f(i,n) for(int i=0;i<n;i++)
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 214783647;
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,-1,0,1 };
const double PI = 3.14159265959;

lint tc, cnt;
lint n, k;
lint num;
lint ans;
priority_queue<pair<int,int>> npq;
priority_queue<pair<int, int>> ppq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x, m;
		cin >> x >> m;
		if (x > 0) {
			ppq.push({ x,m });
		}
		else {
			npq.push({ -x,m });
		}
	}

	while (!ppq.empty()) {
		int cur = k;
		while (cur > 0) {
			int x = ppq.top().first;
			int m = ppq.top().second;

			if (cur == k) {
				if (m >= cur) {
					if (m % k == 0) {
						ppq.pop();
					}
					else {
						ppq.push({ x,m % k });
					}
					
					ans += 2*x*(m/k);
				}
				else {
					ans += 2 * x;
					cur -= m;
					ppq.pop();
				}
			}
			else {
				if (m > cur) {
					ppq.push({ x, m - cur });
					ppq.pop();
					cur = 0;
				}
				else {
					cur -= m;
					ppq.pop();
				}
			}
			if (ppq.empty())
				break;
		}
	}

	while (!npq.empty()) {
		int cur = k;
		while (cur > 0) {
			int x = npq.top().first;
			int m = npq.top().second;

			if (cur == k) {
				if (m >= cur) {
					if (m % k == 0) {
						npq.pop();
					}
					else {
						npq.push({ x,m % k });
					}
		
					ans += 2 * x*(m / k);
				}
				else {
					ans += 2 * x;
					cur -= m;
					npq.pop();
				}
			}
			else {
				if (m > cur) {
					npq.push({ x, m - cur });
					npq.pop();
					cur = 0;
				}
				else {
					cur -= m;
					npq.pop();
				}
			}
			if (npq.empty())
				break;
		}
	}

	cout << ans;
	return 0;
}
