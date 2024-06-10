#include <iostream>
#include <string>
using namespace std;

#define TEST 7

/*
1. 파생클래스에서 함수를 재정의
2. 오버라이딩과 가상 함수 호출
3. 상속이 반복되는 경우 가상 함수 호출
4. 범위 지정 연산자(::)를 이용한 기본 클래스의 가상 함수 호출
5. 소멸자를 가상 함수로 선언
6. 추상 클래스 구현
7. 추상 클래스를 상속받는 파생 클래스 구현
*/

#if TEST == 1 //파생클래스에서 함수를 재정의
class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};
void main() {
	Derived d, * pDer;
	pDer = &d;
	pDer->f(); // Derived::f() 호출
	Base* pBase;
	pBase = pDer; // 업캐스팅
	pBase->f(); // Base::f() 호출
}

#elif TEST == 2 //오버라이딩과 가상 함수 호출

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};
int main() {
	Derived d, * pDer;
	pDer = &d;
	pDer->f(); // Derived::f() 호출
	Base* pBase;
	pBase = pDer; // 업 캐스팅
	pBase->f(); // 동적 바인딩 발생!! Derived::f() 실행
}
/*
자식 클래스의 함수가 virtual 키워드를 포함하지 않아도 
부모 클래스의 가상 함수를 동일한 시그니처로 재정의하면, 
그것이 오버라이딩으로 간주된다는 점입니다. 
virtual 키워드는 자식 클래스에서 다시 명시하지 않아도 
자동으로 가상 함수로 처리됩니다.
*/
#elif TEST == 3 //상속이 반복되는 경우 가상 함수 호출
class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};
class GrandDerived : public Derived {
public:
	void f() { cout << "GrandDerived::f() called" << endl; }
};
int main() {
	GrandDerived g;
	Base* bp;
	Derived* dp;
	GrandDerived* gp;
	bp = dp = gp = &g;
	bp->f();
	dp->f();
	gp->f();
}
#elif TEST == 4 // 범위 지정 연산자(::)를 이용한 기본 클래스의 가상 함수 호출
class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};
class Circle : public Shape {
public:
	virtual void draw() {
		Shape::draw(); // 기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};
int main() {
	Circle circle;
	Shape* pShape = &circle;
	pShape->draw();
	pShape->Shape::draw();
}
#elif TEST == 5 //소멸자를 가상 함수로 선언
class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};
class Derived :public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl; }
};
int main() {
	Derived* dp = new Derived();
	Base* bp = new Derived();

	delete dp;
	delete bp;
}
#elif TEST ==6 //추상 클래스 구현
class Calculator {
public:
	virtual int add(int a, int b) = 0;
	virtual int subtract(int a, int b) = 0;
	virtual double average(int a[], int size) = 0;
};

class GoodCalc :public Calculator {
public:
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	double average(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};

int main() {
	int a[] = { 1,2,3,4,5 };
	Calculator* p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}
#elif TEST == 7 //추상 클래스를 상속받는 파생 클래스 구현
class Calculator {
	void input() {
		cout << "정수 2개를 입력하세요>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};
class Adder :public Calculator {
public:
	int calc(int a, int b) {return a + b;}
};
class Subtractor :public Calculator {
public:
	int calc(int a, int b) { return a - b; }
};

int main() {
	Adder adder;
	Subtractor subtractor;
	adder.run();
	subtractor.run();
}
#endif