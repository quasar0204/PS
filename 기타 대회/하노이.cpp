#include <iostream>;
using namespace std;

int hanoi(int from, int to, int n) {
	if (n == 0)
		return 0;
	
	if (n == 1)
		return 1;

	int pass = 6 - from - to;

	if (from == 1 && to == 3) {
		return hanoi(from, pass, n - 1) + 1 + 1;
	}
	else if (from == 2 && to == 1) {
		return 1 + 1 + hanoi(pass, to, n - 1);
	}
	else {
		return hanoi(from, pass, n - 1) + 1 + hanoi(pass, to, n - 1);
	}
}

int main() {
	for (int i = 1; i <= 4; i++) {
		cout << hanoi(1, 3, i) << '\n';
	}
	return 0;
}
