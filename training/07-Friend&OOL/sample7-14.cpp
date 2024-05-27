#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	// 연산 후 Power 객체의 참조 리턴
	Power& operator<<(int x);
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power::operator<<(int x) {
	this->kick += x;
	this->punch += x;
	return *this;
}

int main() {
	Power a(1, 2);
	a << 3 << 5 << 6;
	a.show();
}