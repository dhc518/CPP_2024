/*���Ӱ��а� 2019180013 ������*/

#include <iostream>

int main() {
    double numbers[5]; 
    double maxNumber;

    std::cout << "5���� �Ǽ��� �Է��ϼ���:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "�Ǽ� " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    maxNumber = numbers[0];

    for (int i = 1; i < 5; ++i) {
        if (numbers[i] > maxNumber) {
            maxNumber = numbers[i];
        }
    }

    std::cout << "���� ū ��: " << maxNumber << std::endl;

    return 0;
}