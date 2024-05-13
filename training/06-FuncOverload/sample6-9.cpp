#include <iostream>
using namespace std;

//static 멤버 사용 : 클래스명과 범위 지정 연산자(::)로 접근

class Person {
public:
	int money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;
	static void addShared(int n) {
		sharedMoney += n;
	}
};

int Person::sharedMoney = 10;  

int main() {
	Person::addShared(50); 
	cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200; 

	Person::sharedMoney = 300; 
	Person::addShared(100);

	cout << han.money << ' '
		<< Person::sharedMoney << endl;
}
