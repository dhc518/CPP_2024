/*���Ӱ��а� 2019180013 ������*/

#include <iostream>
using namespace std;

class Tower {

    int height;

    
public:
    Tower();
    Tower(int h) {
        height = h;
    }

    int getHeight() {
        return height;
    };
};

Tower::Tower() :Tower(1) {};

int main()
{
    Tower myTower;
    Tower seoulTower(100);
    cout << "���̴� " << myTower.getHeight() << "����" << endl;
    cout << "���̴� " << seoulTower.getHeight() << "����"  << endl;
}
