#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() {
		cout << "radius = " << radius << " 인 원" << endl;
	}
	friend Circle& operator+(int x, Circle op);
};
Circle& operator+(int x, Circle op) {
	Circle tmp;
	tmp.radius = op.radius + x;
	return tmp;
}
int main() {
	Circle a(5), b(4);
	b = 1 + a; // b의 반지름을 a의 반지름에 1을 더한 것으로 변경
	a.show();
	b.show();
}