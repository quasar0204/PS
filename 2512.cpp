#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int N;
int M;

int add(int x) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < x)
			sum += arr[i];
		else
			sum += x;
	}
	return sum;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> M;

	sort(arr, arr + N);
	
	for (int i = arr[0]; i < arr[N - 1]; i++) {
		
	}
}