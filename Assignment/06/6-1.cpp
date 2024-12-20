//2019180013 두혁찬

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() {
		cout << "radius = " << radius << " 인 원" << endl;
	}
	friend Circle& operator++(Circle& op);
	friend Circle& operator++(Circle& op,int x);
};

Circle& operator++(Circle &op) {
	op.radius += 1;
	return op;
}

Circle& operator++(Circle& op, int x) {
	Circle tmp;
	tmp = op;
	op.radius += 1;
	return tmp;
}

int main() {
	Circle a(5), b(4);
	++a; // 반지름을 1 증가 시킨다.
	b = a++; // 반지름을 1 증가 시킨다.
	a.show();
	b.show();
}