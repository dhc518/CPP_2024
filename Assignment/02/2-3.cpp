/*게임공학과 2019180013 두혁찬*/

#include <iostream>
#include <cstring> 

#define BUFFER_SIZE 100
int main() {

    char input[BUFFER_SIZE];

    while (true) {
        std::cout << "계속하려면 'yes'를 입력하세요. 종료하려면 아무 키나 입력하세요: ";
        std::cin.getline(input, BUFFER_SIZE);

        if (strcmp(input, "yes") == 0) {
            std::cout << "종료합니다." << std::endl;
            break;
        }
    }

    return 0;
}