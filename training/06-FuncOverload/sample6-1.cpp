#include <iostream>
using namespace std;

int big(int a, int b) {
	if (a <= b) return b;
	else return a;

}

int big(int a[], int size) {
	int n = a[0];

	for (int i = 1; i < size; i++) {
		if (n < a[i]) n = a[i];
	}

	return n;
}

int main() {
	int array[5] = { 1, 9, -2, 8, 6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
}