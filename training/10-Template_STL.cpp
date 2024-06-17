#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define TEST 10

/*
1. 
2. 
3. 
4. 
5. 
6. ���׸� ���� Ŭ���� �����
7. �� ���� ���׸� Ÿ���� ���� Ŭ���� �����
9.  vector �����̳� Ȱ���ϱ�
10. ���ڿ��� �����ϴ� ���� ����� ����
11. iterator�� ����Ͽ� vector�� �����ҿ� 2 ���ϱ�
12. map���� ���� ���� �����
13. sort() �Լ��� �̿��� vector ����

*/

#if TEST == 1 //

#elif TEST == 6 //���׸� ���� Ŭ���� �����

template <class T>
class MyStack {
	int tos;// top of stack
	T data[100]; // T Ÿ���� �迭. ������ ũ��� 100
public:
	MyStack();
	void push(T element); // element�� data [] �迭�� ����
	T pop(); // ������ ž�� �ִ� �����͸� data[] �迭���� ����
};

template <class T>
MyStack<T>::MyStack() { // ������
	tos = -1; // ������ ��� ����
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	tos++;
	data[tos] = element;
}
template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack empty";
		return 0; // ���� ǥ��
	}
	retData = data[tos--];
	return retData;
}
int main() {
	MyStack<int> iStack; // int �� �����ϴ� ����
	iStack.push(3);
	cout << iStack.pop() << endl;
	MyStack<double> dStack; // double �� �����ϴ� ����
	dStack.push(3.5);
	cout << dStack.pop() << endl;
	MyStack<char>* p = new MyStack<char>(); // char�� �����ϴ� ����
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}

#elif TEST == 7 //�� ���� ���׸� Ÿ���� ���� Ŭ���� �����
template <class T1, class T2> // �� ���� ���׸� Ÿ�� ����
class GClass {
	T1 data1;
	T2 data2;
public:
	GClass();
	void set(T1 a, T2 b);
	void get(T1& a, T2& b);
};
template <class T1, class T2>
GClass<T1, T2>::GClass() {
	data1 = 0; data2 = 0;
}
template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
	data1 = a; data2 = b;
}
template <class T1, class T2>
void GClass<T1, T2>::get(T1& a, T2& b) {
	a = data1; b = data2;
}
int main() {
	int a;
	double b;
	GClass<int, double> x;
	x.set(2, 0.5);
	x.get(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;
	char c;
	float d;
	GClass<char, float> y;
	y.set('m', 12.5);
	y.get(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;
}


#elif TEST == 9 //vector �����̳� Ȱ���ϱ�

int main() {
	vector<int> v; // ������ ���� ������ ���� ����
	v.push_back(1); // ���Ϳ� ���� 1 ����
	v.push_back(2); // ���Ϳ� ���� 2 ����
	v.push_back(3); // ���Ϳ� ���� 3 ����
	for (int i = 0; i < v.size(); i++) // ������ ��� ���� ���
		cout << v[i] << " "; // v[i]�� ������ i ��° ����
	cout << endl;
	v[0] = 10; // ������ ù ��° ���Ҹ� 10���� ����
	int n = v[2]; // n�� 3�� ����
	v.at(2) = 5; // ������ 3 ��° ���Ҹ� 5�� ����
	for (int i = 0; i < v.size(); i++) // ������ ��� ���� ���
		cout << v[i] << " "; // v[i]�� ������ i ��° ����
	cout << endl;
}
#elif TEST == 10 //���ڿ��� �����ϴ� ���� ����� ����
int main() {
	vector<string> v; // ������ ���� ������ ���� ����
	string name;
	cout << "�̸��� 5�� �Է��϶�" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">> ";
		cin >> name;
		v.push_back(name);
	}
	string last = v[0];
	for (int i = 1; i < v.size(); i++) // ������ ��� ���� ���
		if (last < v[i])last = v[i];
	


	cout <<"�������� ���� �ڿ� ������ �̸��� "<<last<< endl;
}
#elif TEST == 11 //iterator�� ����Ͽ� vector�� �����ҿ� 2 ���ϱ�
#elif TEST == 12 //map���� ���� ���� �����
#elif TEST == 13 //sort() �Լ��� �̿��� vector ����
#endif