#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string str;
int N;
stack<double> st_num;
vector<int> v;

double cal(char c, double n1, double n2) {
	switch (c) {
	case '*': return n1 * n2;
	case '/': return n1 / n2;
	case '+': return n1 + n2;
	case '-': return n1 - n2;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	for (auto x : str) {
		if (x >= 'A' && x <= 'Z') {
			st_num.push(v[(int)(x-'A')]);
		}
		else {
			double num2 = st_num.top();
			st_num.pop();
			double num1 = st_num.top();
			st_num.pop();
			st_num.push(cal(x, num1, num2));
		}
	}
	printf("%.2lf", st_num.top());
	return 0;
}