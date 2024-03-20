#include "Exp.h"


Exp::Exp() :Exp(1, 1) {

}
Exp::Exp(int b) :Exp(b, 1) {

}
Exp::Exp(int b, int e) {
	base = b;
	exp = e;

}


int Exp::getValue() {
	int value = 1;
	for (int i = 0; i < exp; i++) {
		value *= base;
	}
	return value;
}

bool Exp::equals(Exp &b) {
	if (getValue() == b.getValue()) return true;
	else return false;
}