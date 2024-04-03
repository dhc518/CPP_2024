/*게임공학과 2019180013 두혁찬*/

#include <iostream>

int main() {
    double numbers[5]; 
    double maxNumber;

    std::cout << "5개의 실수를 입력하세요:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "실수 " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    maxNumber = numbers[0];

    for (int i = 1; i < 5; ++i) {
        if (numbers[i] > maxNumber) {
            maxNumber = numbers[i];
        }
    }

    std::cout << "제일 큰 수: " << maxNumber << std::endl;

    return 0;
}