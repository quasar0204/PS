#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;
string str;
int num, n;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front") {
			if (dq.size()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back") {
			if (dq.size()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size") {
			cout << dq.size() << '\n';
		}
		else if (str == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (str == "front") {
			if (dq.size())
				cout << dq.front() << '\n';
			else
				cout << "-1\n";
		}
		else {
			if (dq.size())
				cout << dq.back() << '\n';
			else
				cout << "-1\n";
		}
	}
	return 0;
}