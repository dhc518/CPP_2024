/*게임공학과 2019180013 두혁찬*/

#include <iostream>
using namespace std;

class Oval {
	
	int width;
	int height;
public:
	Oval();
	Oval(int w, int h) {
		width = w;
		height = h;
	}
	~Oval(){
		cout <<"Oval 소멸 : width = " << width << ", height = " << height << endl;
	}

	void set(int w, int h);
	void show();
	int getWidth();
	int getHeight();
};

Oval::Oval() :Oval(1, 1) {}

void Oval::set(int w, int h)
{
	width = w;
	height = h;
}
void Oval::show()
{
	cout << "width = "<<width << ", height = " << height << endl;
}
int Oval::getWidth()
{
	return width;
}
int Oval::getHeight()
{
	return height;
}
int main()
{
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}
