#include <iostream>

class Circle {
	int radius;
public:
	Circle();
	~Circle(){}
	void setRadius(int r) { radius = r; }	
	double getArea() { return 3.14 * radius * radius; }

};

Circle::Circle(){
	radius = 1;
}

int main() {
	std::cout << "�����ϰ��� �ϴ� ���� ����?";
	int n, radius;
	std::cin >> n;
	

	Circle* pArray = new Circle[n];
	for (int i = 0; i < n; i++) {
		std::cout << "��" << i+1 << ": ";
		std::cin >> radius;
		pArray[i].setRadius(radius);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		std::cout << pArray[i].getArea() << " ";
		if (pArray[i].getArea() > 100 && pArray[i].getArea() < 200) count++;
	}

	std::cout << std::endl
		<<"������ 100���� 200 ������ ���� ������ " << count;

	delete[] pArray;

}