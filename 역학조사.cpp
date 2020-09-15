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
int N, M;

vector<int> meet[100001];
int init[100001];
int fin[100001];
int go[100001];
bool visit[100001];
bool flag;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> cnt;
		while (cnt--) {
			cin >> tmp;
			meet[i].push_back(tmp);
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> fin[i];
		init[i] = fin[i];
		if (init[i] == 0) {
			visit[i] = true;
			init[i] = -2;
		}
	}

	for (int i = M-1; i >= 0; i--) {

		flag = false;

		for (int x : meet[i]) {
			if (init[x] == -2) {
				flag = true;
				break;
			}
		}

		if (flag) {
			for (int x : meet[i]) {
				if (init[x] != -2) {
					visit[x] = true;
					init[x] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (init[i] < 0) {
			init[i] = 0;
		}
		go[i] = init[i];
	}

	for (int i = 0; i < M; i++) {
		flag = false;

		for (int x : meet[i]) {
			if (go[x]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			for (int x : meet[i]) {
				go[x] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] && go[i] != fin[i]) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES" << '\n';

	for (int i = 1; i <= N; i++) {
		cout << init[i] << ' ';
	}

	//code end
	return 0;
}