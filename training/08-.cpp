#include <iostream>
#include <string>
using namespace std;

#define TEST 0

/*
1. Point 클래스를 상속받는 ColorPoint 클래스 만들기
2. 상속과 객체 포인터 – 업 캐스팅
3. 상속과 객체 포인터 – 다운 캐스팅
4. protected 멤버에 대한 접근
*/

#if TEST == 0 //Point 클래스를 상속받는 ColorPoint 클래스 만들기

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class Point2 {
	int a, b, c;
public:
	void set2(int a, int b) { this->a = a; this->b = b; }
	void showPoint2() { cout << "(" << a << "," << b << ")" << endl; }
};

class ColorPoint : public Point, public Point2 {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	Point p;
	ColorPoint cp;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
}

#elif TEST == 1 //Point 클래스를 상속받는 ColorPoint 클래스 만들기

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	Point p;
	ColorPoint cp;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
}

#elif TEST == 2 //상속과 객체 포인터 – 업 캐스팅

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; // 업캐스팅
	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
	//pBase->showColorPoint(); 컴파일 오류
}

#elif TEST == 3 //상속과 객체 포인터 – 다운 캐스팅

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	ColorPoint cp;
	ColorPoint* pDer;
	Point* pBase = &cp; // 업캐스팅
	pBase->set(3, 4);
	pBase->showPoint();
	pDer = (ColorPoint*)pBase; // 다운캐스팅
	pDer->setColor("Red"); // 정상 컴파일
	pDer->showColorPoint(); // 정상 컴파일
}

#elif TEST == 4 //protected 멤버에 대한 접근

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint(){ cout << "(" << x << "," << y << ")" << endl; }
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color);
	void showColorPoint();
	bool equals(ColorPoint p);
};

void ColorPoint::setColor(string color) {
	this->color = color;
}
void ColorPoint::showColorPoint() {
	cout << color << ",";
	showPoint();
}
bool ColorPoint::equals(ColorPoint p)
{
	if (x == p.x && y == p.y && color == p.color)
		return true;
	else
		return false;
}

int main() {
	Point p;
	p.set(2, 3);
	p.set(5, 5);
	p.showPoint();

	ColorPoint cp;
	cp.set(10, 10);
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false");
}

#elif TEST == 5



#endif