#include <iostream>
using namespace std;

#define MAX_SIZE 5

double biggest(double x[], int n) {
	double big = x[0];
	for (int i = 0; i < n - 1; i++) {
		if (big < x[i])big = x[i];
	}
	return big;
}

int main() {
	double x[MAX_SIZE];
	cout << " 5���� �Ǽ��� �Է��Ͻÿ�>>";
	for (int i = 0; i < MAX_SIZE; i++) {
		cin >> x[i];
	}
	cout << endl << "���� ū �� = " << biggest(x, MAX_SIZE);


	return 0;
}