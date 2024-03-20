#include <iostream>
#include "Exp.h"

int main() {
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	std::cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << std::endl;
	std::cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << std::endl;

	if (a.equals(b))
		std::cout << "same" << std::endl;
	else
		std::cout << "not same" << std::endl;
}	
