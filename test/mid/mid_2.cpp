#include <iostream>
using namespace std;

int main() {
	char y[20];
	while (1) {
		cout << "�����ϰ� ������yes�� �Է��ϼ���>>";
		cin.getline(y, 20);
		if (strcmp(y,"yes")==0) break;
	}
	return 0;
}