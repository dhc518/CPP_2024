#include <iostream>
#include <string>
using namespace std;

#define TEST 7

/*
1. Point 클래스를 상속받는 ColorPoint 클래스 만들기
2. 상속과 객체 포인터 – 업 캐스팅
3. 상속과 객체 포인터 – 다운 캐스팅
4. protected 멤버에 대한 접근
5. 생성자 매개 변수 전달
6. 다중상속 선언 및 호출
7. 가상 상속으로 다중상속의 모호성 해결
*/

#if TEST == 1 //Point 클래스를 상속받는 ColorPoint 클래스 만들기

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

#elif TEST == 5 //생성자 매개 변수 전달
class TV {
	int size;
public:
	TV(int size) {
		this->size = size;
	}
	int	getSize() {
		return this->size;
	}
};
class WideTV : public TV { // TV를 상속받는 WideTV
	bool videoln;
public:
	WideTV(int size) : TV(size){
		this->videoln = true;
	}
	bool getVideoIn() {
		return videoln;
	}
};
class SmartTV : public WideTV { // WideTV를 상속받는 SmartTV
	string ipAddr;
public:
	SmartTV(string ip, int size):WideTV(size) {
		this->ipAddr = ip;
	}
	string getIpAddr() {
		return this->ipAddr;
	}
};

int main() {
	// 32 인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트 TV 객체 생성
	SmartTV htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "IP="<<htv.getIpAddr() << endl;
}

#elif TEST == 6 //복수의 클래스를 상속받는 ColorPoint 클래스 만들기

class Adder {
protected:
	int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};


// 다중 상속
class Calculator :Adder, Subtractor {

public:
	int calc(char sign, int a, int b) {
		if (sign == '+') return add(a, b);
		else if (sign == '-') return minus(a, b);
	}
};

int main() {
	Calculator handCalculator;
	cout << "2 + 4 = "
		<< handCalculator.calc('+', 2, 4) << endl;
	cout << "100 - 8 = "
		<< handCalculator.calc('-', 100, 8) << endl;
}
#elif TEST == 7 // 가상 상속으로 다중상속의 모호성 해결
class BaseIO {
public:
	int mode;
};
class In : virtual public BaseIO {
public: 
	int readPos;
};
class Out : virtual public BaseIO {
public:
	int writePos;
};
class InOut : public In, public Out {
public:
	bool safe;

};

int main() {
	InOut ioObj;

	ioObj.readPos = 10;
	ioObj.writePos = 20;
	ioObj.safe = true;
	ioObj.mode = 5;

	cout << "ioObj" << endl
		<< "readPos = " << ioObj.readPos << endl 
		<< "writePos = " << ioObj.writePos << endl
		<< "safe = " << ioObj.safe << endl 
		<< "mode = " << ioObj.mode << endl;


}

#endif