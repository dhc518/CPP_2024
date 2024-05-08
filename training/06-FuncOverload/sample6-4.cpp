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
	f(); // 한줄에 빈칸을 10개 출력한다.
	f('%'); // 한 줄에 '%'를 10개 출력한다.
	f('@', 5); // 5 줄에 '@' 문자를 10개 출력한다.
}