#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea();
};

Circle::~Circle() {
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}