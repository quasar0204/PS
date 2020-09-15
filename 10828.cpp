#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N, num;
	string str;
	stack<int> st;

	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> str;
		if ( str == "push" ) {
			cin >> num;
			st.push(num);
		}
		else if ( str == "pop" ) {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if ( str == "size" ) {
			cout << st.size() << "\n";
		}
		else if ( str == "empty" ) {
			cout << st.empty() << "\n";
		}
		else {
			if (st.empty())
				cout << "-1\n";
			else
				cout << st.top() << "\n";
		}
	}

	return 0;
}