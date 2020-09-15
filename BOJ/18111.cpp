#include <bits/stdc++.h>
using namespace std;

int N, M, B;
int MAP[501][501];
int LESS[257], TIME[258];
int MAX;
vector<pair<int, int>> vp;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> B;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
			MAX = MAX < MAP[y][x] ? MAP[y][x] : MAX;
		}

	for (int i = 1; i <= MAX; i++) {
		LESS[i] = LESS[i - 1];
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (MAP[y][x] - i < 0)
					LESS[i]++;
			}
		}
	}
	
	for (int h = MAX; h >= 0; h--) {
		int floor = M * N - LESS[h] + LESS[h - 1];
		if (B >= LESS[h]) {
			vp.push_back({ TIME[h + 1] + LESS[h], 256 - h });
		}
		B = B + (floor);
		TIME[h] = TIME[h + 1] + 2 * floor;
	}
	sort(vp.begin(), vp.end());

	cout << vp[0].first << ' ' << 256 - vp[0].second;

	return 0;
}