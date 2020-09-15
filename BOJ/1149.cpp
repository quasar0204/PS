#include <bits/stdc++.h>
using namespace std;

enum { R = 0, G = 1, B = 2 };
int N;
int ans[3][1001];

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);


	int r, g, b;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> r >> g >> b;
		ans[R][i] = ans[G][i - 1] < ans[B][i - 1] ? ans[G][i - 1] + r : ans[B][i - 1] + r;
		ans[B][i] = ans[G][i - 1] < ans[R][i - 1] ? ans[G][i - 1] + b : ans[R][i - 1] + b;
		ans[G][i] = ans[R][i - 1] < ans[B][i - 1] ? ans[R][i - 1] + g : ans[B][i - 1] + g;
	}

	cout << min(ans[R][N], min(ans[G][N], ans[B][N]));

	return 0;
}