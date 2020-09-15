#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int arr[1000001];
int N;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = N; i >= 1; i--) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 1) {
			dq.push_front(i);
		}
		else if (arr[i] == 2) {
			int temp = dq.front();
			dq.pop_front();
			dq.push_front(i);
			dq.push_front(temp);
		}
		else {
			dq.push_back(i);
		}
	}
	for (auto x : dq) {
		cout << x << ' ';
	}
	return 0;
}