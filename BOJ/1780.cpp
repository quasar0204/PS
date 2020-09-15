#include <iostream>
using namespace std;

int answer[3];
int N;
int paper[2222][2200];

void solve(int x, int y, int n) {
	int num = paper[y][x];
	int nx, ny;
	int flag = 1;

	for (ny = y; ny < (y + n); ny++) {
		for (nx = x; nx < (x + n); nx++) {
			if (num != paper[ny][nx]) {
				flag = 0;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag) {
		answer[num + 1]++;
	}
	else {
		for (ny = y; ny < (y + n); ny += n / 3) {
			for (nx = x; nx < (x + n); nx += n / 3) {
				solve(nx, ny, n / 3);
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++) 
		for (int x = 0; x < N; x++)
			cin >> paper[y][x];

	solve(0, 0, N);
	for (auto x : answer) {
		cout << x << '\n';
	}
	return 0;
}