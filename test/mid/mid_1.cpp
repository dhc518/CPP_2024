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
	cout << " 5개의 실수를 입력하시오>>";
	for (int i = 0; i < MAX_SIZE; i++) {
		cin >> x[i];
	}
	cout << endl << "가장 큰 수 = " << biggest(x, MAX_SIZE);


	return 0;
}