#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	bool operator== (Power op2); // == ������ �Լ� ����
};

void Power::show() {
	cout << "kick=" << kick << ','
		<< "punch=" << punch << endl;
}
	if (this->kick == op2.kick && this->punch == op2.punch)return true;
	else return false;
}