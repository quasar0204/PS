#include <iostream>
#include <algorithm>
using namespace std;

char base[3][3] = { '*','*','*',
					'*',' ','*',
					'*','*','*' };

char answer[10000][10000];
int N;
int X, Y;

void blank(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer[x + i][y + j] = ' ';
		}
	}
}

void solve(int x, int y, int n) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				answer[x + i][y + j] = base[i][j];
			}
		}
		return;
	}
	for (int i = 0; i < n; i += n / 3) {
		for (int j = 0; j < n; j += n / 3) {
			if (i == n / 3 && j == n / 3)
				blank(x + i, y + i, i);
			else {
				solve(x + i, y + j, n / 3);
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	solve(X, Y, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << answer[i][j];
		cout << '\n';
	}
	return 0;
}