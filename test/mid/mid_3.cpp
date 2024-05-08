#include <iostream>
using namespace std;

class Oval {
	int width;
	int height;

public:
	Oval();
	Oval(int w, int h);
	~Oval();

	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
	void set(int w, int h);
	void show();
};
Oval::Oval(){
	this->width = 1;
	this->height = 1;
}
Oval::Oval(int w, int h) {
	this->width = w;
	this->height = h;
}
Oval::~Oval() {
	cout << endl << "Oval ¼Ò¸ê : width = " << this->width << ", height = " << this->height <<endl;
}

void Oval::set(int w, int h) {
	this->width = w;
	this->height = h;
}
void Oval::show() {
	cout << endl << "width = " << this->width << ", height = " << this->height << endl << endl;
}



int main() {

	Oval a, b(3, 4);

	a.set(10, 20);

	a.show();

	cout << b.getWidth() << ", " << b.getHeight() << endl;
}