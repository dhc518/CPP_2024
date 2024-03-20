class Exp {

	int base;
	int exp;
	

 public:
	 Exp();
	 Exp(int b, int e);
	 Exp(int b);

	int getValue();
	int getExp() { return exp; }
	int getBase() { return base; }
	bool equals(Exp &b); 

};