//2019180013 두혁찬

#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount)
        : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {}

    virtual ~Printer() {}

    void print(int pages) {
        if (pages > availableCount) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            printedCount += pages;
            availableCount -= pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    virtual void printDetails() const = 0;
};

class InkJetPrinter : public Printer {
private:
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void printInkJet(int pages) {
        if (pages > availableCount || pages > availableInk) {
            cout << "용지 또는 잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            print(pages);
            availableInk -= pages;
        }
    }

    void printDetails() const override {
        cout << "잉크젯 : " << model << ", " << manufacturer
            << ", 남은 종이 " << availableCount << "장"
            << ", 남은 잉크 " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
private:
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void printLaser(int pages) {
        if (pages > availableCount || pages > availableToner) {
            cout << "용지 또는 토너가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            print(pages);
            availableToner -= pages;
        }
    }

    void printDetails() const override {
        cout << "레이저 : " << model << ", " << manufacturer
            << ", 남은 종이 " << availableCount << "장"
            << ", 남은 토너 " << availableToner << endl;
    }
};

int main() {

    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);


    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    inkjet.printDetails();
    laser.printDetails();


    char continuePrinting;
    do {
        int printerType, pages;
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> printerType >> pages;

        if (printerType == 1) {
            inkjet.printInkJet(pages);
        }
        else if (printerType == 2) {
            laser.printLaser(pages);
        }

        inkjet.printDetails();
        laser.printDetails();

        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> continuePrinting;
    } while (continuePrinting == 'y');

    return 0;
}
