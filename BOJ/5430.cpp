#include <iostream>
#include <deque>
#include <string>
using namespace std;

int flag = 1;
string str;
int num;
int TC;
bool ERROR;

void in(deque<int>& deq) {
	char tmp;
	int cur;

	cin >> tmp;
	for (int i = 1; i <= 2 * num - 1; i++) {
		if (i % 2) {
			cin >> cur;
			deq.push_back(cur);
		}
		else
			cin >> tmp;
	}
	cin >> tmp;
}

void solve(deque<int>& deq) {
	for (auto x : str) {
		if (x == 'R')
			flag = 1 - flag;
		else {
			if (deq.size()) {
				if (flag)
					deq.pop_front();
				else
					deq.pop_back();
			}
			else {
				ERROR = true;
				return;
			}
		}
	}
}

void pr(deque<int> deq) {
	if (ERROR)
		cout << "error\n";
	else {
		cout << '[';
		if (flag) {
			for (int i = 0; i < (int)deq.size(); i++) {
				cout << deq[i];
				if (i != (int)deq.size() - 1)
					cout << ',';
			}
		}
		else {
			for (int i = (int)deq.size()-1; i >= 0; i--) {
				cout << deq[i];
				if (i != 0)
					cout << ',';
			}
		}
		cout << ']' << '\n';
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	while (TC--) {
		deque<int> dq;
		ERROR = false; flag = 1;

		cin >> str;
		cin >> num;

		in(dq);
		solve(dq);
		pr(dq);
	}
	return 0;
}