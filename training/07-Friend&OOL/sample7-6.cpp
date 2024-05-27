#include <iostream>
using namespace std;

#define Test 1


#if Test == 1

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power& operator+= (Power op2); // += 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch
		<< endl;
}
Power& Power::operator+= (Power op2) {
	this->kick += op2.kick;
	this->punch += op2.punch;
	return *this;
}


int main() {
	Power a(3, 5), b(4, 6);
	a.show();
	b.show();

	Power c = a += b;
	a.show();
	c.show();
}

#elif Test == 2
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator+ (int op2); // + 연산자 함수 선언
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator+(int op2) {
	Power tmp;
	tmp.kick = this->kick + op2;
	tmp.punch = this->punch + op2;
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2;
	a.show();
	b.show();
}

#endif
