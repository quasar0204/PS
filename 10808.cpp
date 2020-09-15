#include <iostream>
#include <string>
using namespace std;

int num[26];

int main() {
	freopen("in.txt", "r", stdin);
	string str;
	cin >> str;

	for (auto x : str)
		num[int(x - 'a')]++;

	for (auto x : num)
		cout << x << ' ';
	return 0;
}