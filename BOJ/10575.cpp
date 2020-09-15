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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
set<string> s1;
set<string> s2;
string arr1[1010101];
string arr2[1010101];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}
	
		for (int i = 0; i < n; i++) {
			s1.insert(arr1[i]);
			s2.insert(arr2[i]);

			cnt++;
			if (s1 == s2) {
				cout << cnt << ' ';
				cnt = 0;
				s1.clear();
				s2.clear();
			}
		}
		cout << '\n';
	}
	//code end
	return 0;
}