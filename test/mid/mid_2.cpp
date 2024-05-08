#include <iostream>
using namespace std;

int main() {
	char y[20];
	while (1) {
		cout << "종료하고 싶으면yes를 입력하세요>>";
		cin.getline(y, 20);
		if (strcmp(y,"yes")==0) break;
	}
	return 0;
}