//2019180013 ������

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
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            printedCount += pages;
            availableCount -= pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
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
            cout << "���� �Ǵ� ��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            print(pages);
            availableInk -= pages;
        }
    }

    void printDetails() const override {
        cout << "��ũ�� : " << model << ", " << manufacturer
            << ", ���� ���� " << availableCount << "��"
            << ", ���� ��ũ " << availableInk << endl;
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
            cout << "���� �Ǵ� ��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            print(pages);
            availableToner -= pages;
        }
    }

    void printDetails() const override {
        cout << "������ : " << model << ", " << manufacturer
            << ", ���� ���� " << availableCount << "��"
            << ", ���� ��� " << availableToner << endl;
    }
};

int main() {

    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);


    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
    inkjet.printDetails();
    laser.printDetails();


    char continuePrinting;
    do {
        int printerType, pages;
        cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> printerType >> pages;

        if (printerType == 1) {
            inkjet.printInkJet(pages);
        }
        else if (printerType == 2) {
            laser.printLaser(pages);
        }

        inkjet.printDetails();
        laser.printDetails();

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
        cin >> continuePrinting;
    } while (continuePrinting == 'y');

    return 0;
}
