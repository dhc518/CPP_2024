//묵시적 복사 생성에 의해 복사 생성자가 자동 호출되는 경우

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Person { // Person 클래스 선언
	char* name;
	int id;
public:
	Person(int id, const char* name); // 생성자
	Person(const Person& person); // 복사 생성자
	~Person(); // 소멸자
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) { // 생성자
	this->id = id;
	int len = strlen(name); // name의 문자 개수
	this->name = new char[len + 1]; // name 문자열 공간 핟당
	strcpy(this->name, name); // name에 문자열 복사
	cout << "원본 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}
Person::Person(const Person& person) { // 복사 생성자
	this->id = person.id; // id 값 복사
	int len = strlen(person.name);// name의 문자 개수
	this->name = new char[len + 1]; // name을 위한 공간 핟당
	strcpy(this->name, person.name); // name의 문자열 복사
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << " || 복사 객체의 이름 " << person.name << endl;
}
Person::~Person() {// 소멸자
	if (name) // 만일 name에 동적 할당된 배열이 있으면
		cout << "삭제되는 객체의 이름 " << this->name << endl;
		delete[] name; // 동적 할당 메모리 소멸	
}
void Person::changeName(const char* name) { // 이름 변경
	if (strlen(name) > strlen(this->name))
		return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
	cout << "변경전 객체의 이름 " << this->name;
	strcpy(this->name, name);
	cout << " || 변경후 객체의 이름 " << this->name << endl;
	
}


void f(Person person) {
	
	person.changeName("dummy");
}
Person g() {
	cout << endl;
	Person mother(2, "Jane");
	return mother;//함수 호출이 끝나고 객체를 리턴해줄 때 생성되는 복사생성자
}
int main() {
	Person father(1, "Kitae");
	Person son = father;
	cout << endl;//다른 함수에서 이름 변경시 실행되는 복사 생성자
	f(father);	
	//g();// 리턴해준 값을 받을 변수가 존재하지 않을경우 바로 객체를 삭제
	//Person daughter = g();//리턴해줄 값을 받을 변수가 있을 시 변수에 대한 생성자는 따로 실행 되지 않음
	son = g();//_CRT_SECURITYCRITICAL_ATTRIBUTE : __CRTDECL operator delete
	cout<<endl;
}
