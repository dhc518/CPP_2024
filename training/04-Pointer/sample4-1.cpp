#include <iostream>

class Circle {
	int radius;

public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	~Circle();
	double getArea();
};
Circle::~Circle() {
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	Circle pizza(30);

	std::cout << donut.getArea() << std::endl;

	Circle* p;
	p = &donut;

	std::cout << p->getArea() << std::endl;
	std::cout << (*p).getArea() << std::endl;

	p = &pizza;
	std::cout << p->getArea() << std::endl;
	std::cout << (*p).getArea() << std::endl;

}
