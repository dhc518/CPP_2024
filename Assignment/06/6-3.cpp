#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; };
};class NamedCircle :public Circle {	string name;public:	NamedCircle(int r = 0, string name = "default") :Circle(r){ this->name = name; }	void setName(string n) { this->name = n; }	string getName() { return this->name; }	void compareArea(NamedCircle c[]);};void compareArea(NamedCircle c[]) {	int big = c[0].getArea();	string name = c[0].getName();	for (int i = 0; i < sizeof(c); i++) {		if (big < c[i].getArea()) {			big = c[i].getArea();			name = c[i].getName();		}	}	cout << "\n가장 면적이 큰 피자는 " << name << "입니다" << endl;}int main() {	NamedCircle c[5];	for (int i = 0; i-1< sizeof(c); i++) {		int radius;		string name;		cout << i + 1 << ">>";		cin >> radius;		cin >> name;		c[i].setRadius(radius);		c[i].setName(name);	}	compareArea(c);}