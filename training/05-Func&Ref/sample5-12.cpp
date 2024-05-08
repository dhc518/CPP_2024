//������ ���� ������ ���� ���� �����ڰ� �ڵ� ȣ��Ǵ� ���

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Person { // Person Ŭ���� ����
	char* name;
	int id;
public:
	Person(int id, const char* name); // ������
	Person(const Person& person); // ���� ������
	~Person(); // �Ҹ���
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) { // ������
	this->id = id;
	int len = strlen(name); // name�� ���� ����
	this->name = new char[len + 1]; // name ���ڿ� ���� ����
	strcpy(this->name, name); // name�� ���ڿ� ����
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << endl;
}
Person::Person(const Person& person) { // ���� ������
	this->id = person.id; // id �� ����
	int len = strlen(person.name);// name�� ���� ����
	this->name = new char[len + 1]; // name�� ���� ���� ����
	strcpy(this->name, person.name); // name�� ���ڿ� ����
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << " || ���� ��ü�� �̸� " << person.name << endl;
}
Person::~Person() {// �Ҹ���
	if (name) // ���� name�� ���� �Ҵ�� �迭�� ������
		cout << "�����Ǵ� ��ü�� �̸� " << this->name << endl;
		delete[] name; // ���� �Ҵ� �޸� �Ҹ�	
}
void Person::changeName(const char* name) { // �̸� ����
	if (strlen(name) > strlen(this->name))
		return; // ���� name�� �Ҵ�� �޸𸮺��� �� �̸����� �ٲ� �� ����.
	cout << "������ ��ü�� �̸� " << this->name;
	strcpy(this->name, name);
	cout << " || ������ ��ü�� �̸� " << this->name << endl;
	
}


void f(Person person) {
	
	person.changeName("dummy");
}
Person g() {
	cout << endl;
	Person mother(2, "Jane");
	return mother;//�Լ� ȣ���� ������ ��ü�� �������� �� �����Ǵ� ���������
}
int main() {
	Person father(1, "Kitae");
	Person son = father;
	cout << endl;//�ٸ� �Լ����� �̸� ����� ����Ǵ� ���� ������
	f(father);	
	//g();// �������� ���� ���� ������ �������� ������� �ٷ� ��ü�� ����
	//Person daughter = g();//�������� ���� ���� ������ ���� �� ������ ���� �����ڴ� ���� ���� ���� ����
	son = g();//_CRT_SECURITYCRITICAL_ATTRIBUTE : __CRTDECL operator delete
	cout<<endl;
}
