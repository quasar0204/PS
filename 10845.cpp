#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
int n;
string str;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	while (n--) {
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (q.size()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			cout << q.empty() << '\n';
		}
		else if (str == "front") {
			if (q.size())
				cout << q.front() << '\n';
			else
				cout << "-1\n";
		}
		else {
			if (q.size())
				cout << q.back() << '\n';
			else
				cout << "-1\n";
		}
	}
	return 0;
}