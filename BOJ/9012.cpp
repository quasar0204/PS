#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	string s;

	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int flag = 0;
		stack<char> st;
		cin >> s;
		for (auto x : s) {
			if (x == '(') {
				st.push('(');
			}
			else {
				if (st.empty()) {
					flag = 1;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (flag || st.size()) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << "\n";
		}
	}
	return 0;
}