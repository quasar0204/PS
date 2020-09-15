#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int N, K;

void jo() {
	for (int i = 1; i < K; i++) {
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	q.pop();
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << '<';
	while (N--) {
		jo();
		if (N == 0) {
			cout << '>';
		}
		else {
			cout << ", ";
		}
	}
	return 0;
}