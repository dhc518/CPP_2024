/*게임공학과 2019180013 두혁찬*/

#include <iostream>

int main() {
    std::cout << "****한국공학반점에 오신 것을 환영합니다****" << std::endl;

    int menu;
    int quantity;

    while (true) {
        std::cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>> ";
        std::cin >> menu;

        if (menu == 4) {
            std::cout << "금일 영업은 끝났습니다." << std::endl;
            break;
        }
        else if (menu < 1 || menu > 3) {
            std::cout << "다시 주문해주세요." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }

        std::cout << "몇인분? ";
        std::cin >> quantity;

        if (quantity <= 0) {
            std::cout << "다시 주문해주세요." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (menu) {
        case 1:
            std::cout << "짬뽕 " << quantity << "인분 나왔습니다." << std::endl;
            break;
        case 2:
            std::cout << "짜장 " << quantity << "인분 나왔습니다." << std::endl;
            break;
        case 3:
            std::cout << "군만두 " << quantity << "인분 나왔습니다." << std::endl;
            break;
        default:
            std::cout << "잘못된 입력입니다." << std::endl;
        }
    }

    return 0;
}
