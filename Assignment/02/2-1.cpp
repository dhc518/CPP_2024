/*���Ӱ��а� 2019180013 ������*/

#include <iostream>
#include <cstring>


int toNum(const char* word) {
	if (strcmp(word, "����") == 0)
		return -1;
	else if (strcmp(word, "����") == 0)
		return 0;
	else if (strcmp(word, "��") == 0)
		return 1;
	else
		std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;
		return 2; // ��ȿ���� ���� �Է�
}
void RSP(int P1, int P2) {

	if (P1 == P2) {
		std::cout << "�����ϴ�." << std::endl;
	}
	else{
		if (P1 == -1) {
			if(P2 == 0) std::cout << "�����2�� �̰���ϴ�." << std::endl;
			else std::cout << "�����1�� �̰���ϴ�." << std::endl;
		}
		else if (P1 == 0) {
			if (P2 == -1) std::cout << "�����1�� �̰���ϴ�." << std::endl;
			else std::cout << "�����2�� �̰���ϴ�." << std::endl;
		}
		else if (P1 == 1) {
			if (P2 == -1) std::cout << "�����2�� �̰���ϴ�." << std::endl;
			else std::cout << "�����1�� �̰���ϴ�." << std::endl;
		}		
	}
}
int main() {
	char p1[10];
	char p2[10];
	int P1, P2;

	std::cout << "���� ���� �� ������ �մϴ�.����, ����, �� �߿��� �Է��ϼ���." << std::endl;

	std::cout << "�����1>> ";
	std::cin >> p1;
	P1 = toNum(p1);
	if (P1 == 2) return 1;

	std::cout << "�����2>> ";
	std::cin >> p2;
	P2 = toNum(p2);
	if (P2 == 2) return 1;

	RSP(P1, P2);
}