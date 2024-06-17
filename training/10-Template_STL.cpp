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
6. 제네릭 스택 클래스 만들기
7. 두 개의 제네릭 타입을 가진 클래스 만들기
9.  vector 컨테이너 활용하기
10. 문자열을 저장하는 벡터 만들기 연습
11. iterator를 사용하여 vector의 모든원소에 2 곱하기
12. map으로 영한 사전 만들기
13. sort() 함수를 이용한 vector 소팅

*/

#if TEST == 1 //

#elif TEST == 6 //제네릭 스택 클래스 만들기

template <class T>
class MyStack {
	int tos;// top of stack
	T data[100]; // T 타입의 배열. 스택의 크기는 100
public:
	MyStack();
	void push(T element); // element를 data [] 배열에 삽입
	T pop(); // 스택의 탑에 있는 데이터를 data[] 배열에서 리턴
};

template <class T>
MyStack<T>::MyStack() { // 생성자
	tos = -1; // 스택은 비어 있음
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
		return 0; // 오류 표시
	}
	retData = data[tos--];
	return retData;
}
int main() {
	MyStack<int> iStack; // int 만 저장하는 스택
	iStack.push(3);
	cout << iStack.pop() << endl;
	MyStack<double> dStack; // double 만 저장하는 스택
	dStack.push(3.5);
	cout << dStack.pop() << endl;
	MyStack<char>* p = new MyStack<char>(); // char만 저장하는 스택
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}

#elif TEST == 7 //두 개의 제네릭 타입을 가진 클래스 만들기
template <class T1, class T2> // 두 개의 제네릭 타입 선언
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


#elif TEST == 9 //vector 컨테이너 활용하기

int main() {
	vector<int> v; // 정수만 삽입 가능한 벡터 생성
	v.push_back(1); // 벡터에 정수 1 삽입
	v.push_back(2); // 벡터에 정수 2 삽입
	v.push_back(3); // 벡터에 정수 3 삽입
	for (int i = 0; i < v.size(); i++) // 벡터의 모든 원소 출력
		cout << v[i] << " "; // v[i]는 벡터의 i 번째 원소
	cout << endl;
	v[0] = 10; // 벡터의 첫 번째 원소를 10으로 변경
	int n = v[2]; // n에 3이 저장
	v.at(2) = 5; // 벡터의 3 번째 원소를 5로 변경
	for (int i = 0; i < v.size(); i++) // 벡터의 모든 원소 출력
		cout << v[i] << " "; // v[i]는 벡터의 i 번째 원소
	cout << endl;
}
#elif TEST == 10 //문자열을 저장하는 벡터 만들기 연습
int main() {
	vector<string> v; // 정수만 삽입 가능한 벡터 생성
	string name;
	cout << "이름을 5개 입력하라" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">> ";
		cin >> name;
		v.push_back(name);
	}
	string last = v[0];
	for (int i = 1; i < v.size(); i++) // 벡터의 모든 원소 출력
		if (last < v[i])last = v[i];
	


	cout <<"사전에서 가장 뒤에 나오는 이름은 "<<last<< endl;
}
#elif TEST == 11 //iterator를 사용하여 vector의 모든원소에 2 곱하기
#elif TEST == 12 //map으로 영한 사전 만들기
#elif TEST == 13 //sort() 함수를 이용한 vector 소팅
#endif