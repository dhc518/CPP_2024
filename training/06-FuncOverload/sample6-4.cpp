#include <iostream>
using namespace std;

void f(char c = ' ', int line = 1) {
	for (int l = 0; l < line; l++) {
		for (int i = 0; i < 10; i++) {
			cout << c;
		}
		cout << endl;
	}
	
}

int main() {
	f(); // ���ٿ� ��ĭ�� 10�� ����Ѵ�.
	f('%'); // �� �ٿ� '%'�� 10�� ����Ѵ�.
	f('@', 5); // 5 �ٿ� '@' ���ڸ� 10�� ����Ѵ�.
}