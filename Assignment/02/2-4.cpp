/*���Ӱ��а� 2019180013 ������*/

#include <iostream>

int main() {
    std::cout << "****�ѱ����й����� ���� ���� ȯ���մϴ�****" << std::endl;

    int menu;
    int quantity;

    while (true) {
        std::cout << "«��:1, ¥��:2, ������:3, ����:4>> ";
        std::cin >> menu;

        if (menu == 4) {
            std::cout << "���� ������ �������ϴ�." << std::endl;
            break;
        }
        else if (menu < 1 || menu > 3) {
            std::cout << "�ٽ� �ֹ����ּ���." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }

        std::cout << "���κ�? ";
        std::cin >> quantity;

        if (quantity <= 0) {
            std::cout << "�ٽ� �ֹ����ּ���." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (menu) {
        case 1:
            std::cout << "«�� " << quantity << "�κ� ���Խ��ϴ�." << std::endl;
            break;
        case 2:
            std::cout << "¥�� " << quantity << "�κ� ���Խ��ϴ�." << std::endl;
            break;
        case 3:
            std::cout << "������ " << quantity << "�κ� ���Խ��ϴ�." << std::endl;
            break;
        default:
            std::cout << "�߸��� �Է��Դϴ�." << std::endl;
        }
    }

    return 0;
}
