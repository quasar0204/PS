#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string init;
	cin >> init;
	list<char> L;
	for (auto c : init) L.push_back(c);
	auto cursor = L.end();
	int Q;
	cin >> Q;
	string tmp;
	getline(cin, tmp);
	while (Q--) {
		string op;
		getline(cin, op);
		if (op[0] == 'P') {
			L.insert(cursor, op[2]);
		}
		else if (op[0] == 'L') {
			if (cursor != L.begin())
				cursor--;
		}
		else if (op[0] == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}
	for (auto c : L) cout << c;
}