/*���Ӱ��а� 2019180013 ������*/

#include <iostream>
#include <cstring> 

#define BUFFER_SIZE 100
int main() {

    char input[BUFFER_SIZE];

    while (true) {
        std::cout << "����Ϸ��� 'yes'�� �Է��ϼ���. �����Ϸ��� �ƹ� Ű�� �Է��ϼ���: ";
        std::cin.getline(input, BUFFER_SIZE);

        if (strcmp(input, "yes") == 0) {
            std::cout << "�����մϴ�." << std::endl;
            break;
        }
    }

    return 0;
}