/*게임공학과 2019180013 두혁찬*/

#include <iostream>
using namespace std;

class Account {
	string Owner;
	int accountNum;
	int balance;
public:
	Account(const char* name, int num, int money) {
		Owner = name;
		accountNum = num;
		balance = money;
	}
	string getOwner();
	int inquiry();
	void deposit(int money);
	int withdraw(int money);	
};

string Account::getOwner() {
	return Owner;
}

int Account::inquiry()
{
	return balance;
}

void Account::deposit(int money)
{
	balance += money;
}

int Account::withdraw(int money)
{
	balance -= money;
	return balance;
}

int main()
{
	Account a("kita", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << " 의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << " 의 잔액은 " << a.inquiry() << endl;
}
