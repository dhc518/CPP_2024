#include <iostream>
#include <string>
using namespace std;

#define TEST 7

/*
1. �Ļ�Ŭ�������� �Լ��� ������
2. �������̵��� ���� �Լ� ȣ��
3. ����� �ݺ��Ǵ� ��� ���� �Լ� ȣ��
4. ���� ���� ������(::)�� �̿��� �⺻ Ŭ������ ���� �Լ� ȣ��
5. �Ҹ��ڸ� ���� �Լ��� ����
6. �߻� Ŭ���� ����
7. �߻� Ŭ������ ��ӹ޴� �Ļ� Ŭ���� ����
*/

#if TEST == 1 //�Ļ�Ŭ�������� �Լ��� ������
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
	pDer->f(); // Derived::f() ȣ��
	Base* pBase;
	pBase = pDer; // ��ĳ����
	pBase->f(); // Base::f() ȣ��
}

#elif TEST == 2 //�������̵��� ���� �Լ� ȣ��

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
	pDer->f(); // Derived::f() ȣ��
	Base* pBase;
	pBase = pDer; // �� ĳ����
	pBase->f(); // ���� ���ε� �߻�!! Derived::f() ����
}
/*
�ڽ� Ŭ������ �Լ��� virtual Ű���带 �������� �ʾƵ� 
�θ� Ŭ������ ���� �Լ��� ������ �ñ״�ó�� �������ϸ�, 
�װ��� �������̵����� ���ֵȴٴ� ���Դϴ�. 
virtual Ű����� �ڽ� Ŭ�������� �ٽ� ������� �ʾƵ� 
�ڵ����� ���� �Լ��� ó���˴ϴ�.
*/
#elif TEST == 3 //����� �ݺ��Ǵ� ��� ���� �Լ� ȣ��
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
#elif TEST == 4 // ���� ���� ������(::)�� �̿��� �⺻ Ŭ������ ���� �Լ� ȣ��
class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};
class Circle : public Shape {
public:
	virtual void draw() {
		Shape::draw(); // �⺻ Ŭ������ draw() ȣ��
		cout << "Circle" << endl;
	}
};
int main() {
	Circle circle;
	Shape* pShape = &circle;
	pShape->draw();
	pShape->Shape::draw();
}
#elif TEST == 5 //�Ҹ��ڸ� ���� �Լ��� ����
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
#elif TEST ==6 //�߻� Ŭ���� ����
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
#elif TEST == 7 //�߻� Ŭ������ ��ӹ޴� �Ļ� Ŭ���� ����
class Calculator {
	void input() {
		cout << "���� 2���� �Է��ϼ���>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "���� ���� " << calc(a, b) << endl;
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