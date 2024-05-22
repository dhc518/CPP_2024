#include <iostream>
using namespace std;

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager;
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height)return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {
	dest.width = src.width; dest.height = src.height;
}