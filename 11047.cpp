#include <bits/stdc++.h>
using namespace std;

int money[10];
int N, K;
int cnt;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> money[i];
	for (int i = N - 1; i >= 0; i--) {
		cnt += (K / money[i]);
		K = K % money[i];
	}

	cout << cnt;

	return 0;
}