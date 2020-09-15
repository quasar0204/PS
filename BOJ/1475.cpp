#include <bits/stdc++.h>
using namespace std;

int num[10];

int main() {
	freopen("in.txt", "r", stdin);
	int room, M;

	cin >> room;

	while (room) {
		num[room % 10]++;
		room /= 10;
	}
	num[6] = (num[6] + num[9] + 1) / 2;
	num[9] = num[6];
	M = *max_element(num, num + 10);
	M = M ? M : 1;
	cout << M;

	return 0;
}