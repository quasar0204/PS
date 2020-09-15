#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;
string str;

int pr(char c) {
	switch (c) {
	case '(': return 0;
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (auto x : str) {
		if (x >= 'A' && x <= 'Z') {
			cout << x;
			continue;
		}
		switch (x) {
			case '(' :
				st.push(x);
				break;
			case ')' :
				while (st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
				break;
			default :
				if (st.empty() || st.top() == '(') {
					st.push(x);
					break;
				}
				else {
					while (pr(st.top()) >= pr(x)) {
						cout << st.top();
						st.pop();
						if (st.empty()) {
							break;
						}
					}
					st.push(x);
				}
		}
	}
	while (st.size()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}